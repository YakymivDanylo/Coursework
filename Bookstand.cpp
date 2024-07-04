//
// Created by danyl on 28.06.2024.
//

#include "Bookstand.h"
Bookstand::Bookstand()
: id(0),book(){};

Bookstand::Bookstand(int id, Book book)
:id{id},book(){}

Bookstand::~Bookstand() {
    cout<<"Bookstand number "<<id<<" was deleted"<<endl;
}

 ostream &operator <<(ostream &os, Bookstand &obj){
     os << " \t" << obj.id;
     os<<obj.book;
     return os;
}
 istream &operator >>(istream &is, Bookstand &obj){
    is>>obj.id>>obj.book;
     return is;
}

Bookstand::Bookstand(const Bookstand &other)
:id(other.id),book(other.book){}

Bookstand::Bookstand(Bookstand &&other)
:id(other.id),book(other.book){
    other.id=0;
    other.book=Book();
}

int Bookstand::getId() const {return id;}
void Bookstand::setId(int id) {this->id=id;}

void Bookstand::getBookstand() const {
    cout<<"ID of the bookstand: "<<id<<endl;
    book.getBook();
}

