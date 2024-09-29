
#include "Person.h"
#include <iostream>
Person::Person()
: Person{"unknown", "unknown", "unknown"}
{}

Person::Person(std::string name, std::string surname, std::string last_name)
:name(name),surname(surname),last_name(last_name){}

ostream &operator<<(ostream &os,const Person& obj){
    os<<obj.name<<"\t"<<obj.surname<<"\t"<<obj.last_name;
    return os;
}

istream &operator>>(istream &is, Person &obj){
    is>>obj.name>>obj.surname>>obj.last_name;
    return is;
}

Person::Person(const Person &other)
:name(other.name),surname(other.surname),last_name(other.last_name){}

Person::Person(Person &&other)
:name(other.name),surname(other.surname),last_name(other.last_name){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
}
