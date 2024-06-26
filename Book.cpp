//
// Created by danyl on 24.06.2024.
//

#include "Book.h"
#include "iostream"

Book::Book()
        :Book("unknown",0.0,0){}

Book::Book(string name, float price, int id)
:name(name),price(price),id(id){}

Book::~Book() {
    cout<<"Book: "<<name<<" "<<id<<" was deleted";
}

ostream &operator<<(ostream &os, Book &obj){
    os<<obj.name<<"\t"<<obj.price<<" \t"<<obj.id<<endl;
    return os;
}
istream &operator>>(istream &is, Book& obj){
    is>>obj.name>>obj.price>>obj.id;
    return is;
}

Book Book::operator=(const Book &rhs) {
    if(this==&rhs)
        return *this;
    else{
        name=rhs.name;
        price=rhs.price;
        id=rhs.id;
        return *this;
    }
}
Book::Book(const Book &other)
:name(other.name),price(other.price),id(other.id){}
Book::Book(Book &&other)
:name(other.name),price(other.price),id(other.id){
    other.name="unknown";
    other.price=0;
    other.id=0;
}
string Book::getName() {
    return name;
}
float Book::getPrice() {
    return price;
}
int Book::getId() {
    return id;
}

void Book::getBook() const {
    cout<<" Name of the book: "<<name<<" Price: "<<price<<" ID: "<<id<<endl;
}

