#include "RPN.hpp"

RPN::RPN()
{
    
}

RPN::RPN(const RPN& orig)
{
    *this = orig;
}

RPN& RPN::operator=(const RPN& orig)
{
    if (this != &orig)
    {
        _op_stack = orig._op_stack;
        _operation = orig._operation;
        _tokens = orig._tokens;
    }
    return *this;    
}

RPN::RPN(const std::string& input)
{
    if (input.empty())
        throw "empty operation";
    size_t i = 0;
    while (i < input.length())
    {
        while (i < input.length() && input[i] == ' ')
            i++;
        if (i >= input.length())
            throw "empty operation";
        _tokens.push_back(std::vector<char>());

        while (i < input.length() && input[i] != ' ')
        {
            _tokens.back().push_back(input[i]);
            i++;
        }
    }
    parse();
}

bool RPN::isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::parse()        
{    
    _operation.reserve(_tokens.size());                          
    for (size_t i = 0; i < _tokens.size(); i++)
    {
        std::string current;
        current.reserve(_tokens[i].size());
        for(size_t j = 0; j < _tokens[i].size(); j++)
        {
            current.push_back(_tokens[i][j]);
        }
        if (current.length() > 1 || (!isdigit(current[0]) && !isoperator(current[0])))
            throw "invalid token";
        _operation.push_back(current[0]);
    }   
}

void RPN::calculate()
{
    size_t i = 0;
    std::string operators("+-/*");
    while (i < _operation.length())
    {
        size_t pos = operators.find(_operation[i]);
        if (pos == std::string::npos)
            _op_stack.push(_operation[i] - '0');
        else
        {
            if (_op_stack.size() < 2)
                throw "invalid operation";
            int a = _op_stack.top();
            _op_stack.pop();
            int b = _op_stack.top();
            _op_stack.pop();
            int res = 0;
            switch (operators[pos])
            {
                case '+' :
                    res = a + b;
                    break;
                case '-' :
                    res = b - a;
                    break;
                case '*' :
                    res = a * b;
                    break;
                case '/' :
                    (a == 0) ? throw "division by zero" : res = b / a;
                    break;
            }
            _op_stack.push(res);
        }
        i++;
    }
    if (_op_stack.size() > 1)
        throw "invalid operation";
    std::cout << _op_stack.top() << std::endl; 
}

RPN::~RPN()
{

}