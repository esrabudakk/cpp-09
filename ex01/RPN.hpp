//
// Created by ebudak on 7/14/23.
//

#ifndef CPP09_RPN_HPP
#define CPP09_RPN_HPP

#include <iostream>
#include "stack"
#include <cstring>

using std::endl;
using std::cout;
using std::string;

class RPN {
private:
    std::stack<string> inputStack;

public:
    RPN();
    ~RPN();
    RPN(const RPN &src);
    RPN operator=(const RPN &src);
    RPN(const string &input);
    void printStack();

    class NoInputException : public std::exception {
        const char *what() const throw() {
            return "Error: No input to operate";
        }
    };
    class InvalidArgumentException : public std::exception {
        const char *what() const throw() {
            return "Error: Invalid argument";
        }
    };
};


#endif //CPP09_RPN_HPP
