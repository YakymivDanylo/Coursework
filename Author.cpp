//
// Created by danyl on 24.06.2024.
//

#include "Author.h"
#include "Book.h"
#include <iostream>
#include <vector>
Author::Author()
    : Person(), book(){}

Author::Author(string name, string surname, string last_name, Book book)
: book{book}, Person(name, surname, last_name){}

Author::~Author() noexcept
{cout<<name<<" "<<surname<<" "<<last_name<<" was deleted"<<endl;}


ostream &operator<<(ostream &os,  Author &obj){
       os << static_cast<const Person&>(obj) << " ";
       os<<obj.book<<endl;
        return os;
}
istream &operator>>(istream &is,Author &obj ){
    is>>static_cast <Person&>(obj);
    is>>obj.book;
    return is;
}
Author::Author(const Author &other)
 : Person(other), book(other.book) {}

 Author::Author(Author &&other)
 : Person(other), book(other.book){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
    other.book=Book();
}

string Author::getName() {return name;}
string Author::getSurname() {return surname;}
string Author::getLastName() {return  last_name;}

void Author::getAuthor() const {
    cout<<" "<<name<<" "<<surname<<" "<<last_name<<endl;
    book.getBook();
}

void Author::addBook(const Book &book) {
    if(this->book.getId()==book.getId()){
        cerr<<"This ID already exists"<<endl;
        return;
    }
    this->book = book;
}

Book Author::getBook() {
    return book;
}









