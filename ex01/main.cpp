#include "RPN.hpp"

int main (int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw "invalid arguments";
        std::string input(av[1]);
        RPN rpn(input);
        rpn.calculate();
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
}