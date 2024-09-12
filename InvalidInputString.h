//
// Created by danyl on 12.09.2024.
//
#include "iostream"
#ifndef COURSEWORK_INVALIDSTRING_H
#define COURSEWORK_INVALIDSTRING_H
class InvalidInputString: public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid input!Enter a string!";
    }
};
#endif //COURSEWORK_INVALIDSTRING_H
