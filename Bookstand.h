//
// Created by danyl on 28.06.2024.
//

#ifndef COURSEWORK_BOOKSTAND_H
#define COURSEWORK_BOOKSTAND_H
#include "Book.h"
#include "fstream"
#include "vector"
#include "ErroOpening.h"
#include "memory"

class Bookstand{
private:
    int id;
    Book book;
public:
    Bookstand();
    Bookstand(int id,Book book);
    ~Bookstand();
    friend ostream &operator <<(ostream &os, Bookstand &obj);
    friend istream &operator >>(istream &is, Bookstand &obj);
    Bookstand(const Bookstand &other);
    Bookstand(Bookstand &&other);
    int getId() const;
    void setId(int id);
    Book getBook();
    void getBookstand () const;
    void addBook();


};


#endif //COURSEWORK_BOOKSTAND_H
