//
// Created by Esra Budak on 7/15/23.
//
#include "PMergeMe.hpp"


bool isConvenient(string c){

    string repo = "0123456789";
    bool con = false;
    for (int i = 0; i < c.length(); i++) {
        if(repo.find(c[i]) != std::string::npos){
            con = true;
        }
        else{
            con = false;
            return con;
        }
    }
    return  con;
}

int main(int argc, char **argv){
    try{

        if(argc < 2)
            throw PMergeMe::NoInputException();

        for (int i = 1; i <argc ; i++) {
            if(!isConvenient(argv[i])){
                throw PMergeMe::InvalidArgumentException();
            }
        }
        PMergeMe pMergeMe(argc, argv);
    }
    catch (std::exception &e){
        cout << e.what() << endl;
    }
}