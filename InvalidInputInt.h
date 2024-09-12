//
// Created by danyl on 12.09.2024.
//
#include "iostream"
#ifndef COURSEWORK_INVALIDINPUTINT_H
#define COURSEWORK_INVALIDINPUTINT_H
class InvalidInputInt: public std::exception{
public:
    const char * what() const noexcept override{
        return "Invalid input!Enter an integer!";
    }
};
#endif //COURSEWORK_INVALIDINPUTINT_H
