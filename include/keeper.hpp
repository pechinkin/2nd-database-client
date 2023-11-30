#ifndef KEEPER_H
#define KEEPER_H
#include <sign.hpp>
class Keeper
{
private:
    Sign **base = nullptr;
    int size;
    void DeleteElementPrivate(int num);
    
public:
    Keeper();
    ~Keeper();
    void AddElement();
    void AddElement(Sign *temp_elem);
    void DeleteElement();
    void CopyElement();
    void ChangeElement();
    void ShowBySign();
    void ShowAll();
    
    void Menu();
};

#endif
