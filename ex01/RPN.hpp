#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

class RPN
{
    private:
        std::stack<int> _op_stack;
        std::string _operation;
        std::vector<std::vector<char> > _tokens;
        RPN();
        public:
        
        RPN(const std::string& input);
        RPN(const RPN& orig);
        RPN& operator=(const RPN& orig);
        bool isoperator(char c);
        void parse();
        void calculate();

        ~RPN();
};

#endif