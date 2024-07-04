//
// Created by danyl on 24.06.2024.
//

#ifndef COURSEWORK_BOOK_H
#define COURSEWORK_BOOK_H
#include <iostream>
using namespace std;
class Book {
private:
    int counter = 1;
    string name;
    float price;
    int id;
public:
    Book();
    Book(string name, float price, int id);
    ~Book();
    friend ostream &operator <<(ostream &os, Book &obj);
    friend istream &operator >>(istream &is, Book &obj);
    Book operator=(const Book &rhs);
    void operator--(){}
    void operator++(){}
    Book(const Book& other);
    Book( Book&& other);
    string getName();
    float getPrice() const;
    int getId() const ;
    void getBook() const;


};


#endif //COURSEWORK_BOOK_H
