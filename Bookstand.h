//
// Created by danyl on 28.06.2024.
//

#ifndef COURSEWORK_BOOKSTAND_H
#define COURSEWORK_BOOKSTAND_H
#include "Book.h"
#include "fstream"
#include "vector"
#include "ErroOpening.h"
#include "memory"

class Bookstand{
private:
    int id;
    vector<Book> books;
public:
    Bookstand();
    Bookstand(int id);
    ~Bookstand();
    friend ostream &operator <<(ostream &os, Bookstand &obj);
    friend istream &operator >>(istream &is, Bookstand &obj);
    Bookstand(const Bookstand &other);
    Bookstand(Bookstand &&other);
    int getId() const;
    void setId(int id);
    const vector<Book>& getBooks() const;
    void getBookstand () const;
    void addBook(const Book& book);
    void writeBookAndBookStToFile( const Bookstand &bookstand);

    unique_ptr<Bookstand> findBookstandById(const string filename, int booksatndId){
        ifstream file(filename);
        if (!file.is_open()){
            cerr<<"Error opening file: "<<endl;
            return nullptr;
        }
        Bookstand bookstand;
        string name;
        int bsId;
        double price;
        int id;
        while (file>>bsId>>name>>price>>id){
            if (bsId==booksatndId){
                return make_unique<Bookstand>(bookstand);
            }
        }
        return nullptr;
    }

};


#endif //COURSEWORK_BOOKSTAND_H
