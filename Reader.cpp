//
// Created by danyl on 27.06.2024.
//

#include "Reader.h"
Reader::Reader()
    :People(),books(){}

Reader::Reader(string &name, string &surname, string &last_name, Book &book)
    :books(book), People(name,surname,last_name){}

    Reader::~Reader() noexcept {
    cout<<"Object of class Reader was deleted";
}

ostream &operator<<(ostream &os,  Reader &obj){
    os<<static_cast<const People&>(obj);
    os<<obj.books<<endl;
    return os;
}
istream &operator>>(istream &is,Reader &obj ){
    is>>static_cast< People&>(obj);
    is>>obj.books;
    return is;
}

Reader::Reader(const Reader &other)
: People(other),books(other.books){}

Reader::Reader(Reader &&other)
: People(other),books(other.books){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
    other.books=Book();
}

string Reader::getName() {return name;}
string Reader::getSurname() {return surname;}
string Reader::getLastName() {return  last_name;}
Book Reader::getBook() {return books;}

