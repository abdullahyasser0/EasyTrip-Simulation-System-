#pragma once

#include <iostream>
#include "Passenger.h"
using namespace std;
class Events {
protected:
    string PassengerType, Priority;
    int ID, STRT, END, Hours, Minutes,OnOffTime;
    char EventType;
public:
    virtual Passenger* execute() = 0;
    virtual int getid() = 0;
    virtual int getHours() = 0;
    virtual int getMinutes() = 0;
    virtual char getetype() = 0;


};
