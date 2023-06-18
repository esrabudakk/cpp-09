//
// Created by ebudak on 6/18/23.
//

#include "DataControl.hpp"

DataControl::DataControl() {

}

DataControl::~DataControl() {

}

DataControl::DataControl(const DataControl &src) {

}

DataControl &DataControl::operator=(const DataControl &src) {
    return *this;
}

DataControl::DataControl(const string &data) {
    std::ifstream myFile(data.c_str());

    if (myFile.is_open()) {
        std::string line;

        while (getline(myFile, line)) {
            dataVector.push_back(line);
        }

        myFile.close();
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }
}

void DataControl::printData() {
    for (std::vector<std::string>::iterator it = dataVector.begin(); it != dataVector.end(); ++it) {
        std::cout << *it << std::endl;
    }
}