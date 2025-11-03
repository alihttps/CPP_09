#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, double> csv;
    bool _valid_date(const std::string& date);
    double _valid_value(const std::string& number);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& orig);
    BitcoinExchange& operator=(const BitcoinExchange& orig);
    void fillmap();
    void execute(const char* inputfile);
    void calculate(const std::string& date, double value);

    class ErrorOpeningFile : public std::exception
    {
        public:
            virtual char const* what() const throw()
            {
                return "Error : can't open the file";
            }
    };

    class InvalidFileFormat : public std::exception
    {
        public:
            virtual char const* what() const throw()
            {
                return "Error : invalid file format";
            }
    };

    class EmptyFile : public std::exception
    {
        public:
            virtual char const* what() const throw()
            {
                return "Error : empty file";
            }
    };
    ~BitcoinExchange();
};
#endif