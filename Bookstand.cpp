//
// Created by danyl on 28.06.2024.
//

#include "Bookstand.h"
Bookstand::Bookstand()
: id(0),book(){};
Bookstand::Bookstand(int id, Book book)
:id{id},book(){}
 ostream &operator <<(ostream &os, Bookstand &obj){
     os << " \t" << obj.id;
     os<<obj.book;
     return os;
}
 istream &operator >>(istream &is, Bookstand &obj){
    is>>obj.id>>obj.book;
     return is;
}

int Bookstand::getId() const {return id;}
void Bookstand::setId(int id) {this->id=id;}

