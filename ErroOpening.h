//
// Created by danyl on 05.07.2024.
//

#ifndef COURSEWORK_ERROOPENING_H
#define COURSEWORK_ERROOPENING_H
#include "iostream"
class ErrorOpening: public std::exception{
public:
    ErrorOpening()=default;
    ~ErrorOpening()=default;
    const char *what() const noexcept override{
        return "Error opening file";
    }
};
#endif //COURSEWORK_ERROOPENING_H
