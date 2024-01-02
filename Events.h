#pragma once
#include <iostream>
#include "Passenger.h"
#include "stations.h"
using namespace std;
class Events {
protected:
    string PassengerType, Priority;
    int ID, STRT, END, Hours, Minutes,OnOffTime;
    char EventType;
public:
    virtual void execute(Stations<Nodestation*> S) = 0;
    virtual int getid() = 0;
    virtual int getHours() = 0;
    virtual int getMinutes() = 0;
    virtual char getetype() = 0;


};
