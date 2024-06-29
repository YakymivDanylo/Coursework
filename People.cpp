//
// Created by danyl on 24.06.2024.
//

#include "People.h"
#include <iostream>
People::People()
: People{"unknown","unknown","unknown"}{}

People::People(std::string name, std::string surname, std::string last_name)
:name(name),surname(surname),last_name(last_name){}

ostream &operator<<(ostream &os,const People& obj){
    os<<obj.name<<"\t"<<obj.surname<<"\t"<<obj.last_name;
    return os;
}

istream &operator>>(istream &is, People &obj){
    is>>obj.name>>obj.surname>>obj.last_name;
    return is;
}

People::People(const People &other)
:name(other.name),surname(other.surname),last_name(other.last_name){}

People::People(People &&other)
:name(other.name),surname(other.surname),last_name(other.last_name){
    other.name="unknown";
    other.surname="unknown";
    other.last_name="unknown";
}
