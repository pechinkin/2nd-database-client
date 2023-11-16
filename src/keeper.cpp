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
    AddElement(day, month, year, name, surname);
}

void Keeper::AddElement(int _day, int _month, int _year, string _name, string _surname)
{
    int counter = 0, last = 0;
    Sign* new_elem = new Sign(_day, _month, _year, _name, _surname);
    
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
    std::cout << "[added]" << std::endl;
}


void Keeper::CopyElement()
{
    try {
        if (size == 0) {
            std::cout << "nothing to copy" << std::endl;
        }
        else {
            int w = 0;
            ShowAll();
            std::cout << "which do you want to copy?" << std::endl;
            if (!(std::cin >> w) || (w < 0) || (w >= size)) {
                throw std::logic_error("invalid number to copy");
            }
            else {
                AddElement(base[w]->GetDay(), base[w]->GetMonth(), base[w]->GetYear(), base[w]->GetName(), base[w]->GetSurname());
                std::cout << "[copied]" << std::endl;
            }
            }
    }
    catch (const std::logic_error& ex) {std::cout << "Logic_error: " << ex.what() << std::endl;}
    
}


void Keeper::DeleteElement()
{
    int num;
    if (size == 0) {
        std::cout << "nothing to delete" << std::endl;
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
        std::cout << "empty" << std::endl;
    }
    for (int i  = 0; i != size; i++) {
        std::cout << '#' << i << ' '<< base[i];
    }
}

void Keeper::ShowBySign()
{
    if (size == 0) {
        std::cout << "nothing to show" << std::endl;
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
            std::cout << "nothing to show" << std::endl;
    }
}

void Keeper::Menu()
{
    int w = 0;
    while (w != 6) {
        std::cout << "1. add \n2. delete \n3. copy \n4. show all \n5. show by sign \n6. quit \n";
        if (!(std::cin >> w) || w > 6 || w < 1 )
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
                        ShowAll();
                        break;
                    case 5:
                        ShowBySign();
                        break;
                    case 6:
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

