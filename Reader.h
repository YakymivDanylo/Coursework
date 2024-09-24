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
    int idR;

public:
    Reader();
    Reader( string name, string surname, string last_name, int idR);
    ~Reader();
    friend ostream &operator <<(ostream &os, Reader &obj);
    friend istream &operator >>(istream &is, Reader &obj);
    Reader &operator=(const Reader &rhs);
    Reader(const Reader &other);
    Reader( Reader &&other);
    string getName() override;
    string getSurname() override;
    string getLastName() override;

    void setNameReader(const string& newName);
    void setSurnameReader(const string& newSurname);
    void setLastNameReader(const string& newLastName);
    void setIdReader(int newId);

    int getID();
    void getReader() const;
    [[maybe_unused]] bool search();
    void write_log();
};


#endif //COURSEWORK_READER_H
