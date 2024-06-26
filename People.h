//
// Created by danyl on 24.06.2024.
//

#ifndef COURSEWORK_PEOPLE_H
#define COURSEWORK_PEOPLE_H
#include <iostream>
#include <string>
using namespace std;
class People {
protected:
    string name;
    string surname;
    string last_name;
public:
    People();
    People(string name, string surname,string last_name);
    ~People()=default;
    friend ostream &operator <<(ostream &os, const People &obj);

    virtual string getName()=0;
    virtual string getSurname()=0;
    virtual string getLastName()=0;
    virtual void print(ostream &os)=0;
};


#endif //COURSEWORK_PEOPLE_H
