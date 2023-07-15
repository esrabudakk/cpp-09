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