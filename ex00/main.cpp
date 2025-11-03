#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
    try
    {
        if (ac < 2)
        {
            throw BitcoinExchange::ErrorOpeningFile();
        }
        BitcoinExchange btc;
        btc.execute(av[1]);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
