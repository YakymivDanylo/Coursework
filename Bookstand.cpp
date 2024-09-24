//
// Created by danyl on 28.06.2024.
//

#include "Bookstand.h"

Bookstand::Bookstand()
        : id(0), book()
        {
    write_log();
        }

Bookstand::Bookstand(int id, Book book)
        : id{id},book{book}
        {
write_log();
        }

Bookstand::~Bookstand() {
ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)",ios_base::app);
auto now = chrono::system_clock::now();
time_t log_time = chrono::system_clock::to_time_t(now);
foutLog <<ctime(&log_time) <<"\t::\t"
<<"Bookstand object was deleted."<<endl;
}

ostream &operator<<(ostream &os, Bookstand &obj) {
    os<<obj.id<<" "<<obj.book;
    return os;
}

istream &operator>>(istream &is, Bookstand &obj) {
    is >> obj.id>>obj.book;
    return is;
}

Bookstand::Bookstand(const Bookstand &other)
        : id(other.id), book(other.book) {}


string Bookstand::getNameBook() {
    return book.getName();}

double Bookstand::getPriceBook() {
    return book.getPrice();
}

int Bookstand::getIdBook() {
    return book.getId();
}



Bookstand::Bookstand(Bookstand &&other)
        : id(other.id), book(other.book) {
    other.id = 0;
    other.book = Book();
}

[[maybe_unused]] int Bookstand::getIdBookstand() const { return id; }

void Bookstand::setBookstandId(int newIdBookstand) {
    id = newIdBookstand;
}

void Bookstand::setBook(Book newBook) {
    book = newBook;
}


[[maybe_unused]] void Bookstand::getBookstand() const {
    cout << "ID of the bookstand: " << id << endl;
}

[[maybe_unused]] Book Bookstand::getBook() {
    return book;
}

void Bookstand::write_log() {
    ofstream foutLog(R"(D:\Coursework\Database\Logs.txt)",ios_base::app);
    auto now = chrono::system_clock::now();
    time_t log_time = chrono::system_clock::to_time_t(now);
    foutLog<<ctime(&log_time)<<"\t::\t"
    <<"Bookstand object was created with parameters: "<<endl
    <<"\tid: "<<id<<endl;
}











