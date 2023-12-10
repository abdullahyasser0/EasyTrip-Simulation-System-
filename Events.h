#ifndef EVENTS_H
#define EVENTS_H
#include <iostream>
#include "Passenger.h"
using namespace std;
class Events {
protected:
    string PassengerType, Priority;
    int ID, STRT, END, Hours, Minutes,OnOffTime;

public:
    virtual Passenger* execute() = 0;
    virtual int getid() = 0;
};
#endif