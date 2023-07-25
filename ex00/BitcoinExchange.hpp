//
// Created by ebudak on 6/18/23.
//

#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <sstream>  // <--- std::istringstream için gerekli
#include "fstream"
#include "stdlib.h"


using std::endl;
using std::cout;
using std::string;


class BitcoinExchange {
private:
    std::map<string, float> dataMap;

public:
    BitcoinExchange();
    BitcoinExchange(const string &data, const string &input);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);
    void printData();
    void errorCase(const string &line);
    void takeRate(const string &line);
    std::string invalidDateCheck(const std::string &date) ;

    class NoInputException : public std::exception {
        const char *what() const throw() {
            return "Error: could not open file.";
        }
    };

    class PositiveNumberException : public std::exception {
        const char *what() const throw() {
            return "Error: not a positive number.";
        }
    };

    class TooLargeNumberException : public std::exception {
        const char *what() const throw() {
            return "Error: too large a number.";
        }
    };
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &value);

#endif //CPP09_BITCOINEXCHANGE_HPP
