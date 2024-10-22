//
// Created by danyl on 03.07.2024.
//

#ifndef COURSEWORK_WRONGCHOICE_H
#define COURSEWORK_WRONGCHOICE_H
#include <iostream>
class WrongChoice: public runtime_error{
public:
    WrongChoice(): runtime_error("Wrong choice! Check what you choose! "){}
};


#endif //COURSEWORK_WRONGCHOICE_H
