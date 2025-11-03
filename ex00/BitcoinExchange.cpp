#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    fillmap();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& orig)
{
    *this = orig;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& orig)
{
    if (this != &orig)
    {
        this->csv = orig.csv;
    }
    return *this;
}

void BitcoinExchange::fillmap()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        throw ErrorOpeningFile();
    }
    std::string line;
    if (std::getline(file, line))
    {
        if (line != "date,exchange_rate")
        {
            throw InvalidFileFormat();
        }
    }
    else
    {
        std::cerr << "Error: empty file." << std::endl;
        return;
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string pricestr;
        if (std::getline(ss, date, ',') && std::getline(ss, pricestr))
        {
            csv[date] = strtod(pricestr.c_str(), NULL);
        }
    }
    file.close();
}

void BitcoinExchange::execute(const char* inputfile)
{
    std::ifstream input(inputfile);
    double value;
    if (!input.is_open())
    {
        throw ErrorOpeningFile();
    }
    std::string line;
    if (std::getline(input, line))
    {
        if (line != "date | value")
        {
            throw InvalidFileFormat();
        } 
    }
    else
    {
        throw EmptyFile();
    }
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string numstr;
        std::getline(ss, date, '|');
        if (!date.empty())
            date.erase(date.size() - 1);
        std::getline(ss, numstr, '|');
        {
            if (numstr.empty())
            {
                std::cout << "empty value" << std::endl;
                continue;
            }
        }
        if (_valid_date(date) == false)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        value = _valid_value(numstr);

        if (value != -1)
            calculate(date, value);
    }
    input.close();

}

bool BitcoinExchange::_valid_date(const std::string& date)
{
    std::istringstream iss(date);
    int year;
    int month;
    int day;
    char dash1;
    char dash2;
    if (!(iss >> year >> dash1 >>  month >> dash2 >> day))
        return false;
    if (dash1 != '-' || dash2 != '-')
        return false;
    if (month < 1 || month > 12)
        return false;\
    int daysOfEachMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysOfEachMonth[month - 1])
        return false;
    return true;
        
}

double BitcoinExchange::_valid_value(const std::string& value)
{
    double dvalue;
    std::istringstream iss(value);
    iss >> dvalue;
    if (dvalue < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return -1;
    }
    if (dvalue > 1000)
    {
        std::cout << "Error: too large a number" << std::endl;
        return -1;
    }
    return dvalue;
}

void BitcoinExchange::calculate(const std::string& date, double value)
{
    std::map<std::string , double>::iterator it = csv.lower_bound(date);
    if(it == csv.end())
    {
        --it;
    }
    else if(it->first != date)
    {
        if (it == csv.begin())
        {
            std::cout << "date too early" << std::endl;
            return;
        }
        else
            --it;
    }  
    std::cout << it->first << " ==> " << value << " = " << value * it->second << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{

}