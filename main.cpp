#include <iostream>
#include <sign.hpp>
#include <keeper.hpp>

int main()
{
    Keeper example_keeper;
    try {
        example_keeper.AddElement(14, 5, 2001);
        example_keeper.AddElement(2, 2, 1971);
        example_keeper.AddElement(23, 12, 1991);
        example_keeper.AddElement(14, 5, 1981);
        example_keeper.ShowAll();
    } catch (const std::logic_error& ex) {std::cout << "Logic_error: " << ex.what() << std::endl;}

//    example_keeper.ShowBySign();
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
