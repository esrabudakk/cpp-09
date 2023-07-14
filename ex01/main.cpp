//
// Created by ebudak on 7/14/23.
//

#include "RPN.hpp"

int main(int argc, char **argv){
    try{
        if(argc != 2){
            throw RPN::NoInputException();
        }
        else{
            RPN rpn(argv[1]);

        }
    }
    catch (std::exception &e){
        cout << e.what() << endl;
    }
}