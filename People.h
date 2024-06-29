//
// Created by danyl on 24.06.2024.
//

#ifndef COURSEWORK_PEOPLE_H
#define COURSEWORK_PEOPLE_H
#include <iostream>
#include <string>
using namespace std;
class People {
private:
    string name;
    string surname;
    string last_name;
public:
    friend class Author;
    friend class Reader;
    People();
    People(string name, string surname,string last_name);
    People(const People &other);
    People(People &&other);
    virtual ~People() = 0;
    friend ostream &operator <<(ostream &os, const People &obj);
    friend istream &operator >>(istream &is, People &obj);
    virtual string getName()=0;
    virtual string getSurname()=0;
    virtual string getLastName()=0;
};


#endif //COURSEWORK_PEOPLE_H
