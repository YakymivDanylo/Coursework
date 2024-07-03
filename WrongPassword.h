//
// Created by danyl on 03.07.2024.
//

#ifndef COURSEWORK_WRONGPASSWORD_H
#define COURSEWORK_WRONGPASSWORD_H
#include "iostream"
class WrongPassword: public std::exception{
public:
    WrongPassword()=default;
    ~WrongPassword()=default;
    const char *what() const noexcept override{
        return "Wrong password!!!";
    };
};
#endif //COURSEWORK_WRONGPASSWORD_H
