//
// Created by danyl on 06.07.2024.
//

#ifndef COURSEWORK_SAMEID_H
#define COURSEWORK_SAMEID_H
#include "iostream"
class SameID: public std::exception{
public:
    SameID()=default;
    ~SameID()=default;
    const char *what() const noexcept override{
        return "There is already this ID. Change it!";
    }
};
#endif //COURSEWORK_SAMEID_H
