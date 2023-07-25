//
// Created by ebudak on 7/14/23.
//

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN RPN::operator=(const RPN &src)
{
    return *this;
}

RPN::RPN(const string &input)
{
    float res;
    for (int i = 0; i < input.length(); i++)
    {
        if (!isspace(input[i]) && isdigit(input[i]))
        {
            inputStack.push(std::to_string(input[i] - 48));
        }
        else if (!isspace(input[i]))
        {
            int val1 = atoi(inputStack.top().c_str());
            inputStack.pop();
            int val2 = atoi(inputStack.top().c_str());
            inputStack.pop();

            switch (input[i])
            {
            case '+':
                res = val2 + val1;
                break;
            case '-':
                res = val2 - val1;
                break;
            case '*':
                res = val2 * val1;
                break;
            case '/':
                res = val2 / val1;
            }
            inputStack.push(std::to_string(res));
        }
    }
    cout << res << endl;
}

void RPN::printStack()
{
    std::stack<string> ab = inputStack;

    while (!ab.empty())
    {

        std::cout << ab.top() << std::endl;
        ab.pop();
    }
}
