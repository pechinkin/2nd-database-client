#include <iostream>
#include <sign.hpp>

int main()
{
    Sign *me = new Sign(19, 3, 1999, "n", "s");
    std::cout << me;
    
    Sign *freee = new Sign();
    std::cout << freee;
    
    Sign *copyy = new Sign (me);
    std::cout << copyy;
    
    return 0;
}
