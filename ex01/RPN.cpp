//
// Created by ebudak on 7/14/23.
//

#include "RPN.hpp"

RPN::RPN() {

}

RPN::~RPN() {

}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN RPN::operator=(const RPN &src) {
    *this = src;
    return *this;
}

RPN::RPN(char *input) {

    const char *s = " ";
    char *token = strtok(input, s);

    while (token != NULL) {
       cout << token << endl;
       token = strtok(NULL, s);
    }
}

