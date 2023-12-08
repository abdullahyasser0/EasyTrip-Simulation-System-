#include <iostream>
using namespace std;
class Events {
protected:
    string PassengerType, Priority;
    int ID, STRT, END, Hours, Minutes;

public:
    virtual void execute() = 0;

};