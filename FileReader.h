//
// Created by danyl on 17.10.2024.
//

#ifndef COURSEWORK_FILEREADER_H
#define COURSEWORK_FILEREADER_H
#include <iostream>
using namespace std;
class FileReader{
public:
    virtual string readData(const string& filename) const = 0;
    virtual ~FileReader() = default;
};
#endif //COURSEWORK_FILEREADER_H
