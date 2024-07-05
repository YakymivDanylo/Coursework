//
// Created by danyl on 03.07.2024.
//

#ifndef COURSEWORK_WRONGCHOICE_H
#define COURSEWORK_WRONGCHOICE_H
#include "iostream"
class WrongChoice: public std::exception{
public:
    WrongChoice()=default;
    ~WrongChoice()=default;
    const char *what() const noexcept override{
        return "Wrong choice! Check what you choose! ";
    }
};


#endif //COURSEWORK_WRONGCHOICE_H
