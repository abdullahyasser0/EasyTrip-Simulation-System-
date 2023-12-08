#ifndef EVENTS_H
#define EVENTS_H
#include <iostream>
using namespace std;
class Events {
protected:
    string PassengerType, Priority;
    int ID, STRT, END, Hours, Minutes,OnOffTime;

public:
    virtual void execute() = 0;
    virtual int getid() = 0;
};
#endif