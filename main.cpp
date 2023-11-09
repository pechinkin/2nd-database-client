#include <iostream>
#include <sign.hpp>
#include <keeper.hpp>

int main()
{
    Keeper example_keeper;
    for (int i = 0; i != 12; i++) {
        example_keeper.AddElement();
    }
    example_keeper.ShowAll();
    example_keeper.ShowBySign();
//    Sign *me = new Sign(19, 3, 1999, "n", "s");
//    std::cout << me;
//    
//    Sign *freee = new Sign();
//    std::cout << freee;
//    
//    Sign *copyy = new Sign (me);
//    std::cout << copyy;
    
    return 0;
}
