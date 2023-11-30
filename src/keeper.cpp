#include <iostream>
#include <keeper.hpp>

Keeper::Keeper()
{
    size = 0;
    base = new Sign*[size];
}

Keeper::~Keeper()
{
    delete[] base;
}

void Keeper::AddElement()
{
    string name, surname;
    int year, month, day;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Surame: ";
    std::cin >> surname;
    std::cout << "Year: ";
    std::cin >> year;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Day: ";
    std::cin >> day;
    Sign *new_elem = new Sign(day, month, year, name, surname);
    AddElement(new_elem);
    std::cout << "[added]" << std::endl;

}

void Keeper::AddElement(Sign *temp_elem)
{
    int counter = 0, last = 0;
    Sign* new_elem = new Sign(temp_elem);
    
    {
        for (int i = 0; i != size; i++) {
            if (new_elem->GetYear() >= base[i]->GetYear()) {
                last = i + 1;
                if (new_elem->GetYear() == base[i]->GetYear()) {
                    counter++;
                }
            }
        }
        if (counter > 0) {
            int last_m = last - counter;
            for (int i = last - counter; i != last; i++) {
                if (new_elem->GetMonth() >= base[i]->GetMonth()) {
                    last_m = i + 1;
                }
                if (new_elem->GetMonth() != base[i]->GetMonth()) {
                    counter--;
                }
            }
            last = last_m;
            
            if (counter > 0) {
                int last_d = last - counter;
                for (int i = last - counter; i != last; i++) {
                    if (new_elem->GetDay() >= base[i]->GetDay()) {
                        last_d = i + 1;
                    }
                    if (new_elem->GetDay() != base[i]->GetDay()) {
                        counter--;
                    }

                }
                last = last_d;
            }
        }
    }
    Sign** temp_base = new Sign*[size + 1];
    for (int i = 0; i != last; i++) {
        temp_base[i] = base[i];
    }
    temp_base[last] = new_elem;
    for (int i = last; i != size; i++) {
        temp_base[i + 1] = base [i];
    }
    
    delete[] base;
    base = temp_base;
    size++;
}


void Keeper::CopyElement()
{
    if (size == 0) {
        std::cout << "[nothing to copy]" << std::endl;
    }
    else {
        int w = 0;
        ShowAll();
        std::cout << "which do you want to copy?" << std::endl;
        if (!(std::cin >> w) || (w < 0) || (w >= size)) {
            throw std::logic_error("invalid number to copy");
        }
        else {
            Sign *temp = new Sign(base[w]);
            AddElement(temp);
            std::cout << "[copied]" << std::endl;
            delete temp;
        }
        }
}

void Keeper::ChangeElement()
{
    if (size == 0) {
        std::cout << "[nothing to change]" << std::endl;
    }
    else {
        int w = 0;
        ShowAll();
        std::cout << "which do you want to change?" << std::endl;
        if (!(std::cin >> w) || (w < 0) || (w >= size)) {
            throw std::logic_error("invalid number to copy");
        }
        else {
            Sign *temp = new Sign(base[w]);
            DeleteElementPrivate(w);
            string name, surname;
            int year, month, day;
            int x = 0;
            std::cout << "what do you want to change? \n1. year \n2. month \n3. day \n4. name \n5. surname \n";
            std::cin >> x;
            if (x < 0 || x > 5) {
                throw std::logic_error("invalid number to change");
            }
            switch (x) {
                case 1:
                    std::cout << "enter a year: ";
                    std::cin >> year;
                    temp->SetYear(year);
                    temp->SetZodiacSign();
                    break;
                case 2:
                    std::cout << "enter a month: ";
                    std::cin >> month;
                    temp->SetMonth(month);
                    temp->SetZodiacSign();
                    break;
                case 3:
                    std::cout << "enter a day: ";
                    std::cin >> day;
                    temp->SetDay(day);
                    temp->SetZodiacSign();
                    break;
                case 4:
                    std::cout << "enter a name: ";
                    std::cin >> name;
                    temp->SetName(name);
                    break;
                case 5:
                    std::cout << "enter a surname: ";
                    std::cin >> surname;
                    temp->SetSurname(surname);
                    break;
                    
                default:
                    break;
            }
            AddElement(temp);
            std::cout << "[changed]" << std::endl;
            delete temp;
        }
        }
}

void Keeper::DeleteElementPrivate(int num)
{
    Sign** temp_base = new Sign*[size--];
    for (int i = 0; i != num; i++) {
        temp_base[i] = base [i];
    }
    for (int i = num + 1; i <= size; i++) {
        temp_base[i - 1] = base [i];
    }
    delete[] base;
    base = temp_base;
}

void Keeper::DeleteElement()
{
    int num;
    if (size == 0) {
        std::cout << "[nothing to delete]" << std::endl;
    }
    std::cout << "what do you want to delete?" << std::endl;
    ShowAll();
    if ((std::cin >> num) && (num >= 0) && (num <= size))
    {
        Sign** temp_base = new Sign*[size--];
        for (int i = 0; i != num; i++) {
            temp_base[i] = base [i];
        }
        for (int i = num + 1; i <= size; i++) {
            temp_base[i - 1] = base [i];
        }
        delete[] base;
        base = temp_base;
        std::cout << "[deleted]" << std::endl;
    }
    else
        throw std::logic_error("invalid number of element");

}

void Keeper::ShowAll()
{
    if (size == 0) {
        std::cout << "[empty]" << std::endl;
    }
    for (int i  = 0; i != size; i++) {
        std::cout << '#' << i << ' '<< base[i];
    }
}

void Keeper::ShowBySign()
{
    if (size == 0) {
        std::cout << "[nothing to show]" << std::endl;
        return;
    }
    int sign_num = 0, counter = 0;
    std::cout << "enter a sign (0 - 12):";
    std::cin >> sign_num;
    if (sign_num < 1 || sign_num > 12) throw std::logic_error ("invalid sign");
    for (int i  = 0; i != size; i++) {
        if (base[i]->GetZodiacSign() == sign_num)
        {
            std::cout << base[i];
            counter++;
        }
        if (counter == 0)
            std::cout << "[nothing to show]" << std::endl;
    }
}

void Keeper::Menu()
{
    int w = 0;
    while (w != 7) {
        std::cout << "1. add \n2. delete \n3. copy \n4. change elem \n5. show all \n6. show by sign \n7. quit \n";
        if (!(std::cin >> w) || w > 7 || w < 1 )
        {
            std::cout << "[incorrect. try again]" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            try{
                switch (w) {
                    case 1:
                        AddElement();
                        break;
                    case 2:
                        DeleteElement();
                        break;
                    case 3:
                        CopyElement();
                        break;
                    case 4:
                        ChangeElement();
                        break;
                    case 5:
                        ShowAll();
                        break;
                    case 6:
                        ShowBySign();
                        break;
                    case 7:
                        std::cout << "[quitting]" << std::endl;
                        break;
                        
                    default:
                        break;
                }
            }
            catch (const std::logic_error& ex) {std::cout << "Logic_error: " << ex.what() << std::endl;}
        }
    }
}

