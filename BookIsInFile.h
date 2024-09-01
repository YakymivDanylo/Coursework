//
// Created by danyl on 01.09.2024.
//
#include "iostream"
#ifndef COURSEWORK_BOOKISINFILE_H
#define COURSEWORK_BOOKISINFILE_H
class BookIsInFile: public std::exception{
public:
    BookIsInFile()=default;
    ~BookIsInFile()=default;
    const char *what() const noexcept override{
        return "There is already book with this ID!";
    }
};
#endif //COURSEWORK_BOOKISINFILE_H
