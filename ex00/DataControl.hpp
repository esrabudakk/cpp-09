//
// Created by ebudak on 6/18/23.
//

#ifndef CPP09_DATACONTROL_HPP
#define CPP09_DATACONTROL_HPP

#include <vector>
#include "iostream"
#include "fstream"
using std::endl;
using std::cout;
using std::string;


class DataControl {
private:
    std::vector<std::string> dataVector;
public:
    DataControl();
    ~DataControl();
    DataControl(const DataControl &src);
    DataControl &operator=(const DataControl &src);
    DataControl(const string &data);
    void printData();
};

std::ostream &operator<<(std::ostream &out, const DataControl &value);

#endif //CPP09_DATACONTROL_HPP
