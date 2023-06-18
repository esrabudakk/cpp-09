//
// Created by ebudak on 6/18/23.
//

#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::string;


class BitcoinExchange {
private:

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);

    class NoInputException : public std::exception {
        const char *what() const throw() {
            return "Error: could not open file.";
        }
    };
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &value);

#endif //CPP09_BITCOINEXCHANGE_HPP
