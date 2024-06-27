//
// Created by danyl on 27.06.2024.
//

#ifndef COURSEWORK_READER_H
#define COURSEWORK_READER_H
#include "iostream"
#include "People.h"
#include "Book.h"
using namespace std;

class Reader: public People{
private:
    Book books;
public:
    Reader();
    Reader( string name, string surname, string last_name, Book books);
    friend ostream &operator <<(ostream &os, Reader &obj);
    friend istream &operator >>(istream &is, Reader &obj);
    string getName() override;
    string getSurname() override;
    string getLastName() override;
    virtual void print(ostream &os) override;
    Book getBook();
};


#endif //COURSEWORK_READER_H
