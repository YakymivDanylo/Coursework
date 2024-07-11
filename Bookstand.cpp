//
// Created by danyl on 28.06.2024.
//

#include "Bookstand.h"

Bookstand::Bookstand()
        : id(0) {};

Bookstand::Bookstand(int id)
        : id{id} {}

Bookstand::~Bookstand() {
    cout << "Bookstand number " << id << " was deleted" << endl;
}

ostream &operator<<(ostream &os, Bookstand &obj) {
    for (Book &book: obj.books) {
        os << book << endl;
    }
    return os;
}

istream &operator>>(istream &is, Bookstand &obj) {
    is >> obj.id;
    return is;
}

Bookstand::Bookstand(const Bookstand &other)
        : id(other.id) {}

Bookstand::Bookstand(Bookstand &&other)
        : id(other.id) {
    other.id = 0;
}

int Bookstand::getId() const { return id; }

void Bookstand::setId(int id) { this->id = id; }

const vector<Book> &Bookstand::getBooks() const {return books;}

void Bookstand::getBookstand() const {
    cout << "ID of the bookstand: " << id << endl;
}

void Bookstand::addBook(const Book &book) {
    books.push_back(book);
}

void Bookstand::writeBookAndBookStToFile( const Bookstand &bookstand) {
    ofstream fout(R"(D:\Coursework\Database\Bookstands.txt)",ios_base::app);
    if (fout.is_open()) {
        unique_ptr<int> id{new int{0}};
        unique_ptr<int> idB{new int{0}};
        unique_ptr<string> name{new string {"unknown"}};
        unique_ptr<float> price{new float{0.0}};
        Bookstand bookstand1(*id);
        Book book(*name,*price,*id);
        fout <<bookstand1<<" "<<book<< endl;
    } else {
        cerr<<"Error opening file"<<endl;
    }
    fout.close();
}











