//
// Created by danyl on 26.07.2024.
//
#include "iostream"
#ifndef COURSEWORK_INVALIDINPUT_H
#define COURSEWORK_INVALIDINPUT_H
class InvalidInput: public std::exception{
public:
    const char* what() const noexcept override{
        return "Invalid input!";
    }
};
#endif //COURSEWORK_INVALIDINPUT_H
