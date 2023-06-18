//
// Created by ebudak on 6/18/23.
//

#include "InputControl.hpp"

InputControl::InputControl() {

}

InputControl::~InputControl() {

}

InputControl::InputControl(const InputControl &src) {

}

InputControl &InputControl::operator=(const InputControl &src) {
    return *this;
}

InputControl::InputControl(const string file) {
    std::ifstream myFile(file.c_str());

    if (myFile.is_open()) {
        std::string line;

        while (getline(myFile, line)) {
            inputVector.push_back(line);
        }

        myFile.close();
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }
}


void InputControl::printInput() {
    for (std::vector<std::string>::iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void InputControl::errorCase(){
    size_t pos;
    for (std::vector<std::string>::iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
            string line = *it;
       try {
            pos = line.find('|');
            if (pos != std::string::npos) {
                string date = line.substr(0, pos);
                string value = line.substr(pos + 1);

                if(atol(value.c_str()) < 0)
                    throw PositiveNumberException();
                else if(atol(value.c_str()) > 1000)
                    throw TooLargeNumberException();
                else
                   cout << line << endl;
            }
            else
                throw BadInputException();
    }
       catch (std::exception &e){
            cout << e.what() << endl;
       }
    }
}