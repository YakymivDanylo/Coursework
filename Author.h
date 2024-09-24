//
// Created by danyl on 24.06.2024.
//

#ifndef COURSEWORK_AUTHOR_H
#define COURSEWORK_AUTHOR_H
#include "Person.h"
#include "Book.h"
#include <iostream>
#include "vector"
#include "algorithm"
#include "chrono"
using namespace std;

class Author final : private Person{
private:
    Book book;
public:
    Author();
    Author(string name,string surname,string last_name, Book book);
    ~Author();
    friend ostream &operator <<(ostream &os, Author &obj);
    friend istream &operator >>(istream &is, Author &obj);
    Author(const Author &other);
    Author( Author &&other);
    string getName() override;
    string getSurname() override;
    string getLastName() override;
    void getAuthor() const;

    Book getBook() const;
    string getNameBook();
    double getPriceBook();
    int getId();
    void write_log();

    void setNameAuthor(const string& newName);
    void setSurnameAuthor(const string& newSurname);
    void setLastNameAuthor(const string& newLastName);
    void setBookAuthor(const Book& newBook);

    void addBook(const Book& book);
};


#endif //COURSEWORK_AUTHOR_H
