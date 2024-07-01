//
// Created by danyl on 24.06.2024.
//

#include "Author.h"
#include "Book.h"
#include <iostream>
#include <vector>
Author::Author()
    : People(),books(){}

Author::Author(string &name, string &surname, string &last_name, Book &books)
:books{books}, People(name,surname,last_name){}

Author::~Author() noexcept
{cout<<name<<" "<<surname<<" "<<last_name<<" was deleted";}


ostream &operator<<(ostream &os,  Author &obj){
       os<<static_cast<const People&>(obj);
       os<<obj.books<<endl;
        return os;
}
istream &operator>>(istream &is,Author &obj ){
    is>>static_cast <People&>(obj);
    is>>obj.books;
    return is;
}
Author::Author(const Author &other)
 : People(other),books(other.books) {}

 Author::Author(Author &&other)
 : People(other),books(other.books){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
    other.books=Book();
}

string Author::getName() {return name;}
string Author::getSurname() {return surname;}
string Author::getLastName() {return  last_name;}
Book Author::getBook() {return books;}

void Author::getAuthor() const {
    cout<<"Name of the author: "<<name<<" Surname of the author: "<<surname<<" Last name of the author "<<last_name<<endl;
    books.getBook();
}









