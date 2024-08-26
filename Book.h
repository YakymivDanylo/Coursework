//
// Created by danyl on 24.06.2024.
//

#ifndef COURSEWORK_BOOK_H
#define COURSEWORK_BOOK_H
#include <iostream>
#include "fstream"
#include "memory"
#include <ctime>
#include "chrono"
using namespace std;
class Book : public error_code {
private:
    int counter = 1;
    string name;
    double price;
    int id;
public:
    Book();
    Book(string name, double price, int id);
    ~Book();
    friend ostream &operator <<(ostream &os, Book &obj);
    friend istream &operator >>(istream &is, Book &obj);
    Book operator=(const Book &rhs);
    Book(const Book& other);
    Book( Book&& other);
    string getName();
    double getPrice() const;
    int getId() const ;
    void getBook() const;
    void write_log();

    unique_ptr<Book> findBookById(const string filename,int bookId){
        ifstream file(filename);
        if (!file.is_open()){
            cerr<<"Error opening file: "<<endl;
            return nullptr;
        }

        Book book;
        while (file>>book.name>>book.price>>book.id){
            if (book.id==bookId){
                return make_unique<Book>(book);
            }
        }
        return nullptr;
    }


};


#endif //COURSEWORK_BOOK_H
