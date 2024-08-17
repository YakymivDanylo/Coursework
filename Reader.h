//
// Created by danyl on 27.06.2024.
//

#ifndef COURSEWORK_READER_H
#define COURSEWORK_READER_H
#include "iostream"
#include "Person.h"
#include "Book.h"
#include "fstream"
using namespace std;

class Reader: public Person{
private:
    Book books;
public:
    Reader();
    Reader( string name, string surname, string last_name, Book books);
    ~Reader();
    friend ostream &operator <<(ostream &os, Reader &obj);
    friend istream &operator >>(istream &is, Reader &obj);
    Reader &operator=(const Reader &rhs);
    Reader(const Reader &other);
    Reader( Reader &&other);
    string getName() override;
    string getSurname() override;
    string getLastName() override;
    int getId();
    void getReader() const;
    Book getBook();
    void write_to_a_file();
    bool search();
};


#endif //COURSEWORK_READER_H
