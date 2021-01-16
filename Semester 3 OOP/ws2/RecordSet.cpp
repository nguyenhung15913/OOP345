#define _CRT_SECURE_NO_WARNINGS
#include "RecordSet.h"

namespace sdds {
    RecordSet::RecordSet() : str{nullptr},noOfRec(0) {};

	RecordSet::RecordSet(const string& file) {
        size_t sizeOfstr = 0;
        std::ifstream f(file);
            while (!f.eof()) {
                std::string string;
                getline(f, string, ' ');
                ++sizeOfstr;
            }
        noOfRec = sizeOfstr;  
        f.close();
        str = new std::string[noOfRec];
        size_t index = 0;
        f.open(file);
        while (!f.eof()) {
            getline(f, str[index++], ' ');
        }
        f.close();
	}

    RecordSet::RecordSet(const RecordSet& value) {
        *this = value;
    }


    RecordSet& RecordSet::operator=(const RecordSet& value) {   
        str = nullptr;
        noOfRec = 0;
        if (this != &value) {
            noOfRec = value.noOfRec;
            delete[] str;
            str = new std::string[noOfRec+1];
            for (size_t i = 0; i < noOfRec; i++) {
                str[i] = value.str[i];
            }
        }
        return *this;
    }

    RecordSet::~RecordSet() {
        delete[] str;
    }

    size_t RecordSet::size() {
        return noOfRec;
    }

    std::string RecordSet::getRecord(size_t index) {
        if (index < 0 || index > noOfRec || str == nullptr) {
            return "";
        }
        else {
           return str[index];
        }      
    }

   RecordSet& RecordSet::operator=(RecordSet&& value) noexcept {
       str = nullptr;
       noOfRec = 0;
        if (this != &value) {
            delete[] str;
            str = value.str;
            value.str = nullptr;
            this->noOfRec = value.noOfRec;
            value.noOfRec = 0;
        }
        return *this;
    }

    RecordSet::RecordSet(RecordSet&& value) noexcept {
        *this = std::move(value);
   }
}