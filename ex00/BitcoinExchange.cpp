//
// Created by ebudak on 6/18/23.
//

#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() {

}
BitcoinExchange::BitcoinExchange(const string &data, const string &input) {
    std::ifstream dataFile(data.c_str());

    if (dataFile.is_open()) {
        std::string line;

        while (std::getline(dataFile, line)) {

            std::string::size_type delimiterPos = line.find(',');

            std::string date = line.substr(0, delimiterPos);
            std::string valueStr = line.substr(delimiterPos + 1);

            float exchange_rate;
            std::istringstream(valueStr) >> exchange_rate;  // <--- std::istringstream kullanımı
            dataMap[date] = exchange_rate;
        }

        dataFile.close();
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }

    std::ifstream inputFile(input.c_str());

    if (inputFile.is_open()) {
        std::string line;

        while (getline(inputFile, line)) {
            errorCase(line);
        }
        inputFile.close();
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }


}
BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    return *this;
}


void BitcoinExchange::printData() {
    std::map<string,float>::iterator it = dataMap.begin();
    for(; it != dataMap.end() ; it++){
        std::cout << (*it).first<< ' ' <<(*it).second<< std::endl;
    }
}

void BitcoinExchange::printInput() {
    for (std::vector<std::string>::iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void BitcoinExchange::takeRate(const string &line) {
        std::string::size_type delimiterPos = line.find('|');
        std::string inputDate = line.substr(0, delimiterPos - 1);
        std::string inputValue = line.substr(delimiterPos + 1);

        if(dataMap.find(inputDate) != dataMap.end()) {
            cout << dataMap.find(inputDate)->first << " => " << inputValue << " = " << dataMap.find(inputDate)->second * atof(inputValue.c_str()) << endl;
        }
        else if(dataMap.lower_bound(inputDate) != dataMap.end()){
            cout << dataMap.lower_bound(inputDate)->first << " => " << inputValue << " = " << dataMap.lower_bound(inputDate)->second * atof(inputValue.c_str()) << endl;
        }
}

void BitcoinExchange::errorCase(const string &line){
    size_t pos;
        try {
            pos = line.find('|');
            if (pos != std::string::npos) {
                string date = line.substr(0, pos);
                string value = line.substr(pos + 1);

                if(atol(value.c_str()) < 0)
                    throw PositiveNumberException();
                else if(atof(value.c_str()) > 1000)
                    throw TooLargeNumberException();
                else{
                    takeRate(line);
                }
            }
            else
            {
                cout << "Error bad input => " + line.substr(0, pos) << endl;
            }
        }
        catch (std::exception &e){
            cout << e.what() << endl;
        }

}