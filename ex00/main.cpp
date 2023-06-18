//
// Created by ebudak on 6/18/23.
//
#include <fstream>
#include "BitcoinExchange.hpp"
#include "DataControl.hpp"
#include "InputControl.hpp"

int main(int argc, char **argv){
    try {
        if(argc == 2){
            DataControl d1("data.csv");
//            d1.printData();
            InputControl i1(argv[1]);
//            i1.printInput();
            i1.errorCase();
        }
        else
            throw BitcoinExchange::NoInputException();
    }
    catch (std::exception &e) {
        std::cout << e.what() << endl;
    }

//    d1.printData();
}

//    string myText;
//    std::ifstream myFile;
//    myFile.open(argv[1]);
//
//    while (getline (myFile, myText)) {
//        cout << myText << endl;
//    }
//
//    myFile.close();