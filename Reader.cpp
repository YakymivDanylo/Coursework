//
// Created by danyl on 27.06.2024.
//

#include "Reader.h"
Reader::Reader()
    :People(),books(){}
Reader::Reader(std::string name, std::string surname, std::string last_name, Book book)
    :People(name,surname,last_name),books(book){}
ostream &operator<<(ostream &os,  Reader &obj){
    os << " \t" << obj.name << " \t" << obj.surname << " \t" << obj.last_name << " \t";
    os<<obj.books;
    return os;
}
istream &operator>>(istream &is,Reader &obj ){
    is>>obj.name>>obj.surname>>obj.last_name>>obj.books;
    return is;
}
string Reader::getName() {return name;}
string Reader::getSurname() {return surname;}
string Reader::getLastName() {return  last_name;}
Book Reader::getBook() {return books;}

void Reader::print(std::ostream &os) {
    os<<"Name: "<<name<<"; Surname: "<<surname<<"; Last name: "<<last_name;

}
