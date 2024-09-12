//
// Created by danyl on 12.09.2024.
//
#include "iostream"
#ifndef COURSEWORK_INVALIDSTRING_H
#define COURSEWORK_INVALIDSTRING_H
class InvalidInputInt: public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid input!You have entered an integer expression in the string!Change it to string!";
    }
};
#endif //COURSEWORK_INVALIDSTRING_H
