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
    Sign* new_elem = new Sign();
    {
        new_elem->SetDay(size % 28 + 1);
        new_elem->SetMonth(size % 12 + 1);
        new_elem->SetZodiacSign();
    }
    Sign** temp_base = new Sign*[size + 1];
    for (int i = 0; i != size; i++) {
        temp_base[i] = base[i];
    }
    temp_base[size] = new_elem;
    delete[] base;
    base = temp_base;
    size++;
    std::cout << "[added]" << std::endl;
}

void Keeper::AddElement(int _day, int _month, int _year)
{
    int counter = 0, last = 0;  //ADD COUNTER
    Sign* new_elem = new Sign(_day, _month, _year, "a", "b");
    
    {
        for (int i = 0; i != size; i++) {
            if (_year >= base[i]->GetYear()) {
                last = i + 1;
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

void Keeper::DeleteElement()
{
    int num;
    if (size == 0) {
        throw std::logic_error("nothing to delete");
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
    for (int i  = 0; i != size; i++) {
        std::cout << '#' << i << ' '<< base[i];
    }
}

void Keeper::ShowBySign()
{
    try
    {
        int sign_num;
        std::cout << "enter a sign (0 - 12):";
        std::cin >> sign_num;
        if (sign_num < 1 || sign_num > 12) throw std::logic_error ("invalid sign");
        for (int i  = 0; i != size; i++) {
            if (base[i]->GetZodiacSign() == sign_num)
                std::cout << base[i];
        }
    }
    catch (const std::logic_error& ex) {std::cout << "Logic_error: " << ex.what() << std::endl;}
}
