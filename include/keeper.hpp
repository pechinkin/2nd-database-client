#ifndef KEEPER_H
#define KEEPER_H
#include <sign.hpp>
class Keeper
{
private:
    Sign **base = nullptr;
    int size;
public:
    Keeper();
    ~Keeper();
    void AddElement();
    void AddElement(int _day, int _month, int _year);
    void DeleteElement();
//    void ChangeElement();
//    void CopyElement();
//    void Sort();
    void ShowBySign();
    void ShowAll();
};

#endif
