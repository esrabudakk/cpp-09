//
// Created by Esra Budak on 7/15/23.
//

#ifndef CPP_09_PMERGEME_HPP
#define CPP_09_PMERGEME_HPP


#include <iostream>
#include "stack"
#include <cstring>

using std::endl;
using std::cout;
using std::string;

class PMergeMe {
private:
    std::stack<string> inputStack;

public:
    PMergeMe();
    ~PMergeMe();
    PMergeMe(const PMergeMe &src);
    PMergeMe operator=(const PMergeMe &src);

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

#endif //CPP_09_PMERGEME_HPP
