//
// Created by ebudak on 6/18/23.
//
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
    try {
        if(argc == 2) {
            BitcoinExchange b ("data.csv", argv[1]);
        }
        else
            throw BitcoinExchange::NoInputException();
    }
    catch (std::exception &e) {
        std::cout << e.what() << endl;
    }
}
