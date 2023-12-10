#ifndef PASSENGER
#define PASSENGER
#include<iostream>
using namespace std;


//welcome kahla
class Passenger
{
private:
    int ID;
    int startStation, endStation;
    int OnOffTime, Hours,Minutes;
    string Priority,type;

public:
    Passenger(int id,int hours, int mins, int startStation, int endStation, int OnoffTime, string& priority)
        : ID(id), Hours(hours),Minutes(mins), startStation(startStation), endStation(endStation),OnOffTime(OnoffTime), Priority(priority)
    {
    }

    int getID() const
    {
        return ID;
    }

    int getStartStation()
    {
        return startStation;
    }

    int getEndStation()
    {
        return endStation;
    }

    string& getPriority()
    {
        
        return Priority;
    }
	
	string& getType()
    {
        return type;
    }
};
#endif
