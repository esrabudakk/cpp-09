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
    srand(time(NULL));
	cout << "Before: ";
    printVector();
    cout << endl;
    clock_t start1 = clock();
	inputVector = mergeInsertSortVector(inputVector);
	clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

	clock_t start2 = clock();
    inputList = mergeInsertSortList(inputList);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;
	cout << "After: ";
	printVector();
    cout << endl;
	cout << "Time to process a range of " << inputVector.size() << " elements with std::vector container: " << time1 << " us" << endl;
	cout << "Time to process a range of " << inputList.size() << " elements with std::list container: " << time2 << " us" << endl;
    
    
}
std::vector<int> PMergeMe::mergeVector( std::vector<int>& left,  std::vector<int>& right){
   std::vector<int> result;
   std::vector<int>::iterator itLeft = left.begin();
   std::vector<int>::iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft < *itRight) {
            result.push_back(*itLeft);
            ++itLeft;
        } else {
            result.push_back(*itRight);
            ++itRight;
        }
    }
    result.insert(result.end(), itLeft, left.end());
    result.insert(result.end(), itRight, right.end());

    return result;
}

void PMergeMe::printVector(){

    std::vector<int>::iterator it = inputVector.begin();

    for(; it != inputVector.end(); it++){
        cout << *it << " " ;
    }
}


std::vector<int> PMergeMe::mergeInsertSortVector(std::vector<int>& tempVector){
    static int threshold = 4;
    std::vector<int>::iterator it = tempVector.begin();

    if(tempVector.size() <= threshold){
        for(; it != tempVector.end(); it++){
            int temp = *it;
            std::vector<int>::iterator it2 = it; 
            while(it2 != tempVector.begin() && *(it2 - 1) > temp){
                *it2 = *(it2 -1);
                it2--;
            }
            *it2 = temp;
        }
        return tempVector;
    }
    else {

        size_t mid =  std::floor(tempVector.size() / 2.0);
        std::vector<int> left(tempVector.begin(), tempVector.begin() + mid);
        std::vector<int> right(tempVector.begin() + mid, tempVector.end());
        
        left = mergeInsertSortVector(left);
        right = mergeInsertSortVector(right);

        return mergeVector(left, right);
    }

}

std::list<int> PMergeMe::mergeInsertSortList(std::list<int>& tempList) {
    static int threshold = 4;

    std::list<int>::iterator it = std::next(tempList.begin());
        if (tempList.size() <= threshold) {
            for (; it != tempList.end(); ++it) {
                int temp = *it;
                std::list<int>::iterator j = it;
                while (j != tempList.begin() && *(std::prev(j)) > temp) {
                    *j = *(std::prev(j));
                    --j;
                }
                *j = temp;
            }
            return tempList;
        } else {
            std::size_t mid = tempList.size() / 2;
            std::list<int> left(tempList.begin(), std::next(tempList.begin(), mid));
            std::list<int> right(std::next(tempList.begin(), mid), tempList.end());
            left = mergeInsertSortList(left);
            right = mergeInsertSortList(right);
            return mergeList(left, right);
        }
}

void PMergeMe::printList(){
    std::list<int>::iterator it = inputList.begin();
    for(; it != inputList.end(); it++){
        cout << *(it) << " ";
    }
}

std::list<int> PMergeMe::mergeList( std::list<int>& left,std::list<int>& right) {
        std::list<int> result;
        std::list<int>::iterator itLeft = left.begin();
        std::list<int>::iterator itRight = right.begin();
        while (itLeft != left.end() && itRight != right.end()) {
            if (*itLeft < *itRight) {
                result.push_back(*itLeft);
                ++itLeft;
            } else {
                result.push_back(*itRight);
                ++itRight;
            }
        }
        result.insert(result.end(), itLeft, left.end());
        result.insert(result.end(), itRight, right.end());
        return result;
}

