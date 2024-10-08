
#ifndef COURSEWORK_BOOKSTAND_H
#define COURSEWORK_BOOKSTAND_H
#include "Book.h"
#include "fstream"
#include "vector"
#include "ErroOpening.h"
#include "memory"
#include "chrono"

class Bookstand{
private:
    int id;
    Book book;
public:
    Bookstand();
    Bookstand(int id,Book book);
    ~Bookstand();
    friend ostream &operator <<(ostream &os, Bookstand &obj);
    friend istream &operator >>(istream &is, Bookstand &obj);
    Bookstand(const Bookstand &other);
    Bookstand(Bookstand &&other);

    string getNameBook() ;
    double getPriceBook();
    int getIdBook();
    int getIdBookstand() const;

    void setBookstandId(int newIdBookstand);
    void setBook(Book newBook);


    [[maybe_unused]] Book getBook();

    [[maybe_unused]] void getBookstand () const;

    void write_log();


};


#endif //COURSEWORK_BOOKSTAND_H
