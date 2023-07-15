//
// Created by ebudak on 7/14/23.
//

#include "RPN.hpp"

bool isConvenient(string c){

    string repo = "0123456789+-/*";
    bool con = false;
    for (int i = 0; i < c.length(); i++) {
        if(!isspace(c[i])){
            if(repo.find(c[i]) != std::string::npos){
                con = true;
            }
            else{
                con = false;
                return con;
            }
        }
    }
    return  con;
}

int main(int argc, char **argv){
    try{
        if(argc != 2){
            throw RPN::NoInputException();
        }
        else{
            string input = argv[1];
            if(isConvenient(input)){
                RPN rpn(input);
            }
            else{
                throw  RPN::InvalidArgumentException();
            }
        }
    }
    catch (std::exception &e){
        cout << e.what() << endl;
    }
}