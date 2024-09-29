
#ifndef COURSEWORK_PERSON_H
#define COURSEWORK_PERSON_H
#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    string surname;
    string last_name;
public:
    friend class Author;
    friend class Reader;
    Person();
    Person(string name, string surname, string last_name);
    Person(const Person &other);
    Person(Person &&other);
     ~Person() = default;
    friend ostream &operator <<(ostream &os, const Person &obj);
    friend istream &operator >>(istream &is, Person &obj);

    virtual string getName()=0;
    virtual string getSurname()=0;
    virtual string getLastName()=0;
};


#endif //COURSEWORK_PERSON_H
