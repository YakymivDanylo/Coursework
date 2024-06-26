//
// Created by danyl on 24.06.2024.
//

#ifndef COURSEWORK_AUTHOR_H
#define COURSEWORK_AUTHOR_H
#include "People.h"
#include "Book.h"
#include <iostream>
#include "vector"
using namespace std;

class Author final : public People{
private:
    vector<Book> books;
public:
    Author();
    Author(string name,string surname,string last_name, vector<Book>& books);
    friend ostream &operator <<(ostream &os,const Author &obj);
    string getName() override;
    string getSurname() override;
    string getLastName() override;
    virtual void print(ostream &os) override;
    vector<Book>& getBooks();
};


#endif //COURSEWORK_AUTHOR_H
