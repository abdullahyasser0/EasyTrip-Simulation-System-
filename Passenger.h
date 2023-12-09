#ifndef PASSENGER
#define PASSENGER
#include<iostream>
using namespace std;

class Passenger
{
private:
    int ID;
    string arrivalTime;
    int startStation, endStation;
    int getOn, getOff;
    string priority,type;

public:
    Passenger(int id, string& arrivalTime, int startStation, int endStation, int getOn, int getOff, string& priority)
        : ID(id), arrivalTime(arrivalTime), startStation(startStation), endStation(endStation), getOn(getOn), getOff(getOff), priority(priority)
    {
    }

    int getID() const
    {
        return ID;
    }

    string& getArrivalTime()
    {
        return arrivalTime;
    }

    int getStartStation()
    {
        return startStation;
    }

    int getEndStation()
    {
        return endStation;
    }

    int getGetOn()
    {
        return getOn;
    }

    int getGetOff()
    {
        return getOff;
    }

    string& getPriority()
    {
        return priority;
    }
	
	string& getType()
    {
        return type;
    }

    void setID(int id)
    {
        ID = id;
    }

    void setArrivalTime(const string& time)
    {
        arrivalTime = time;
    }

    void setStartStation(int start)
    {
        startStation = start;
    }

    void setEndStation(int end)
    {
        endStation = end;
    }

    void setGetOn(int on)
    {
        getOn = on;
    }

    void setGetOff(int off)
    {
        getOff = off;
    }

    void setPriority(string& prio)
    {
        priority = prio;
    }
};
#endif
