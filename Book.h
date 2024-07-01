//
// Created by danyl on 24.06.2024.
//

#ifndef COURSEWORK_BOOK_H
#define COURSEWORK_BOOK_H
#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string name;
    float price;
    int id;
public:
//    friend class Reader;
    Book();
    Book(string name, float price, int id);
    ~Book();
    friend ostream &operator <<(ostream &os, Book &obj);
    friend istream &operator >>(istream &is, Book &obj);
    Book operator=(const Book &rhs);
    Book(const Book& other);
    Book( Book&& other);
    string getName();
    float getPrice();
    int getId();
    void getBook() const;
};


#endif //COURSEWORK_BOOK_H
