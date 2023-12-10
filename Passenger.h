#ifndef PASSENGER
#define PASSENGER
#include<iostream>
using namespace std;


//welcome kahla
class Passenger
{
private:
    int ID,startStation, endStation;
    int OnOffTime, Hours,Minutes;
    string Priority,type;

public:
    // Passenger(string passengerType,int id,int hours, int mins, int startStation, int endStation, int OnoffTime, string& priority)
    //     : type(passengerType),ID(id), Hours(hours),Minutes(mins), startStation(startStation), endStation(endStation),OnOffTime(OnoffTime), Priority(priority)
    // {
    // }

    Passenger(string passengerType, int id, int hours, int mins, int startStation, int endStation, int OnoffTime, string& priority)
    : type(passengerType), ID(id), startStation(startStation), endStation(endStation), OnOffTime(OnoffTime), Hours(hours), Minutes(mins), Priority(priority)
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

    int getPriority()
    {
        
        return Priority;
    }
	
	string& getType()
    {
        return type;
    }
};
#endif
