//
// Created by danyl on 24.06.2024.
//

#include "Author.h"
#include "Book.h"
#include <iostream>
#include <vector>
Author::Author()
    : People(),books(){}
Author::Author(std::string name, std::string surname, std::string last_name, vector<Book>& books)
: People(name,surname,last_name),books(books){}
ostream &operator<<(ostream &os,  Author &obj){
        os << " \t" << obj.name << " \t" << obj.surname << " \t" << obj.last_name << " \t";
        return os;
}
istream &operator>>(istream &is,Author &obj ){
    is>>obj.name>>obj.surname>>obj.last_name>>obj.books;
}

string Author::getName() {return name;}
string Author::getSurname() {return surname;}
string Author::getLastName() {return  last_name;}
vector<Book> &Author::getBooks() {return books;}

void Author::print(std::ostream &os) {
    os<<"Name: "<<name<<"; Surname: "<<surname<<"; Last name: "<<last_name;

}



