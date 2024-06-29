//
// Created by danyl on 28.06.2024.
//

#ifndef COURSEWORK_BOOKSTAND_H
#define COURSEWORK_BOOKSTAND_H
#include "Book.h"

class Bookstand{
private:
    int id;
    Book book;
public:
    Bookstand();
    Bookstand(int id, Book book);
    friend ostream &operator <<(ostream &os, Bookstand &obj);
    friend istream &operator >>(istream &is, Bookstand &obj);
    int getId() const;
    void setId(int id);

};


#endif //COURSEWORK_BOOKSTAND_H
