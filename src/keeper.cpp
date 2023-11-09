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
        temp_base[i] = base [i];
    }
    temp_base[size] = new_elem;
    delete[] base;
    base = temp_base;
    size++;
}

void Keeper::ShowAll()
{
    for (int i  = 0; i != size; i++) {
        std::cout << base[i];
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
