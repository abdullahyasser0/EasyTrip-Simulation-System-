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
        if(Priority=="Aged"){
            return 3;
        }else if(Priority=="POD"){
            return 2;
        }else if(Priority=="pregnant"){
            return 1;
        }else{
            return 0;
        }
    }
	
	string& getType()
    {
        return type;
    }
};
#endif
