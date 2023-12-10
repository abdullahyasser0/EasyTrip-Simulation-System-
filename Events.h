#ifndef EVENTS_H
#define EVENTS_H
#include <iostream>
#include "stations.h"


using namespace std;
class Events {
protected:
    string PassengerType, Priority;
    int ID, STRT, END, Hours, Minutes,OnOffTime;

public:
    virtual void execute(StationsDLL<Passenger*>& stations) = 0;
};
#endif