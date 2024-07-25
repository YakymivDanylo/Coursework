//
// Created by danyl on 25.07.2024.
//
#include <iostream>
#ifndef COURSEWORK_WRONGINPUTDATA_H
#define COURSEWORK_WRONGINPUTDATA_H
class WrongInputData: public std::exception{
public:
    WrongInputData()=default;
    ~WrongInputData()=default;
    const char *what() const noexcept override{
        return "Wrong data! Check what you entered! ";
    }
};
#endif //COURSEWORK_WRONGINPUTDATA_H
