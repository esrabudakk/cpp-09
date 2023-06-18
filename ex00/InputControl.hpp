//
// Created by ebudak on 6/18/23.
//

#ifndef CPP09_INPUTCONTROL_HPP
#define CPP09_INPUTCONTROL_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include "stdlib.h"


using std::endl;
using std::cout;
using std::string;


class InputControl {
private:
    std::vector<std::string> inputVector;
public:
    InputControl();
    ~InputControl();
    InputControl(const InputControl &src);
    InputControl &operator=(const InputControl &src);
    InputControl(const string file);
    void printInput();
    void errorCase();
    class PositiveNumberException : public std::exception {
        const char *what() const throw() {
            return "Error: not a positive number.";
        }
    };
    class BadInputException : public std::exception {
        const char *what() const throw() {
            return "Error: bad input => ";
        }
    };
    class TooLargeNumberException : public std::exception {
        const char *what() const throw() {
            return "Error: too large a number.";
        }
    };
};
std::ostream &operator<<(std::ostream &out, const InputControl &value);


#endif //CPP09_INPUTCONTROL_HPP
