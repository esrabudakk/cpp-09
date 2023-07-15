//
// Created by Esra Budak on 7/15/23.
//

#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::~PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &src) {
    *this = src;
}

PMergeMe PMergeMe::operator=(const PMergeMe &src) {
    return *this;
}

PMergeMe::PMergeMe(int argc, char **argv) {

    for (int i = 1; i < argc; i++) {
        inputVector.push_back(atoi(argv[i]));
        inputList.push_back(atoi(argv[i]));
    }
    sortContainer();
}

void PMergeMe::sortContainer() {


    for (std::vector<int>::iterator it = inputVector.begin(); it < inputVector.end() ; it++) {
        cout << (*it) <<endl;
    }
}