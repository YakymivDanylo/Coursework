//
// Created by danyl on 24.06.2024.
//

#include "People.h"
#include <iostream>
People::People()
: People{"unknown","unknown","unknown"}{}

People::People(std::string name, std::string surname, std::string last_name)
:name(name),surname(surname),last_name(last_name){}

ostream &operator<<(ostream &os, People& obj){
    obj.print(os);
    return os;
}
