//
// Created by Esra Budak on 7/15/23.
//

#ifndef CPP_09_PMERGEME_HPP
#define CPP_09_PMERGEME_HPP


#include <iostream>
#include "stack"
#include <cstring>
#include "vector"
#include "list"
#include <cmath>
#include <ctime>
using std::endl;
using std::cout;
using std::string;

class PMergeMe {
private:
    std::vector<int> inputVector;
    std::list<int> inputList;
public:
    PMergeMe();
    ~PMergeMe();
    PMergeMe(const PMergeMe &src);
    PMergeMe operator=(const PMergeMe &src);
    PMergeMe(int argc, char **argv);
    // void sortContainer();
    std::vector<int> mergeInsertSortVector(std::vector<int> &tempVector);
    std::vector<int> mergeVector(std::vector<int>& left,  std::vector<int>& right);
    std::list<int> mergeInsertSortList(std::list<int>& tempList);
    std::list<int> mergeList(std::list<int>& left,  std::list<int>& right);
    void printList();
    void printVector();

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
