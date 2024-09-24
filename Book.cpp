//
// Created by danyl on 24.06.2024.
//

#include "Book.h"
#include "iostream"

using namespace std;

Book::Book()
        : Book("unknown", 0.0, 0) {
write_log();
}

Book::Book(string name, double price, int id)
        : name(name), price(price), id(id) {
write_log();
}

Book::~Book() {
ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)",ios_base::app);
auto now = chrono::system_clock::now();
time_t log_time = chrono::system_clock::to_time_t(now);
foutLog<<ctime(&log_time)<<"\t::\t"
<<"Book object was deleted."<<endl;

}

ostream &operator<<(ostream &os, Book &obj) {
    os << obj.getName() << "\t" << obj.getPrice() << " \t" << obj.getId() << endl;
    return os;
}

istream &operator>>(istream &is, Book &obj) {
    is >> obj.name >> obj.price >> obj.id;
    return is;
}

Book Book::operator=(const Book &rhs) {
    if (this == &rhs)
        return *this;
    else {
        name = rhs.name;
        price = rhs.price;
        id = rhs.id;
        return *this;
    }

}

Book::Book(const Book &other)
        : name(other.name), price(other.price), id(other.id) {}

Book::Book(Book &&other)
        : name(other.name), price(other.price), id(other.id) {
    other.name = "unknown";
    other.price = 0;
    other.id = 0;
}

string Book::getName() {
    return name;
}

double Book::getPrice() const {
    return price;
}

int Book::getId() const {
    return id;
}

void Book::getBook() const {
    cout << " " << name << " " << price << " " << id << endl;
}

void Book::setNameBook(const std::string &newName) {
    name = newName;
}

void Book::setPriceBook(double newPrice) {
    price = newPrice;
}

void Book::setIDBook(int newID) {
    id = newID;
}

void Book::write_log() {
    ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)",ios_base::app);
    auto now = chrono::system_clock::now();
    time_t log_time = chrono::system_clock::to_time_t(now);
    foutLog<<ctime(&log_time)<<"\t::\t"
    <<"Book object was created with parameters: "<<endl
    <<"\tname of the book: "<<name<<endl
    <<"\tprice: "<<price<<endl
    <<"\tid: "<<id<<endl;
}





