//
// Created by danyl on 28.06.2024.
//

#include "Bookstand.h"

Bookstand::Bookstand()
        : id(0), book()
        {
//            Bookstand bookstand;
//            ofstream fout(R"(D:\Coursework\Database\Constructors_and_Destructors.txt)");
//            fout<<bookstand;
//            fout.close();
        };

Bookstand::Bookstand(int id, Book book)
        : id{id},book{book}
        {
//            Bookstand bookstand;
//            ofstream fout(R"(D:\Coursework\Database\Constructors_and_Destructors.txt)");
//            fout<<bookstand;
//            fout.close();
        }

Bookstand::~Bookstand() {
//    cout << "Bookstand number " << id << " was deleted" << endl;

//    Bookstand bookstand;
//    ofstream fout(R"(D:\Coursework\Database\Constructors_and_Destructors.txt)");
//    fout<<bookstand<<" was deleted"<<endl;
//    fout.close();
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

Bookstand::Bookstand(Bookstand &&other)
        : id(other.id), book(other.book) {
    other.id = 0;
    other.book = Book();
}

int Bookstand::getId() const { return id; }

void Bookstand::setId(int id) { this->id = id; }

void Bookstand::getBookstand() const {
    cout << "ID of the bookstand: " << id << endl;
}

Book Bookstand::getBook() {
    return book;
}

void Bookstand::addBook() {}




//void Bookstand::writeBookAndBookStToFile( const Bookstand &bookstand) {
//    ofstream fout(R"(D:\Coursework\Database\Bookstands.txt)",ios_base::app);
//    if (fout.is_open()) {
//       int id;
//       string name;
//       double price;
//        Bookstand bookstand1(id);
//        Book book(name,price,id);
//        fout <<bookstand1<<" "<<book<< endl;
//    } else {
//        cerr<<"Error opening file"<<endl;
//    }
//    fout.close();
//}











