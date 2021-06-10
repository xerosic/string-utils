#include <iostream>
#include "stringutils.h"


int main()
{
    std::cout << "Simple example for stringutils.h" << std::endl;
    if (string::starts_with("roberto", "rob"))
    {
        std::cout << "It works!" << std::endl;
    }
}
