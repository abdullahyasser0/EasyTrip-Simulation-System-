#pragma once

#include<iostream>
using namespace std;


//welcome kahla
class Passenger
{
private:
    int ID,startStation, endStation;
    int OnOffTime, Hours,Minutes;
    string Priority,type;
    int count = 0;
    int per; // var added for the pri

public: 
Passenger(string passengerType, int id, int hours, int mins, int startstation, int endStation, int OnoffTime, string priority)
    : ID(id), startStation(startstation), endStation(endStation), OnOffTime(OnoffTime), Hours(hours), Minutes(mins), Priority(priority), type(passengerType)
{
}

    Passenger(int id,  int startStation,int hours, int mins)
    : ID(id), startStation(startStation), Hours(hours), Minutes(mins)
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
    string getStrPriopity(){
        return Priority;
    }
    int getPriority()
    {   

        if(Priority==" AGED"){
            return 3;
        }else if(Priority==" POD"){
            return 2;
        }else if(Priority==" pregnant"){
            return 1;
        }
        return per;
    }

    void setPriority(int p) {
            if(Priority==" AGED"){
                per = 3;
            }else if(Priority==" POD"){
                per = 2;
            }else if(Priority==" pregnant"){
                per = 1;
            }
    }
	
	string& getType()
    {
        return type;
    }
    
    // void passPromote(int maxW, int currentTime) {
    //     int waitingTime = currentTime - OnOffTime;

    //     if (waitingTime > maxW) {
    //         setPriority(3); 
    //         cout << "Passenger with ID: " << getID() << " promoted" << endl;
    //     } else {
    //         cout << "Passenger with ID: " << getID() << " has decided to leave the station." << endl;
    //     }
    // }
    bool hasReachedMaxTime(int maxW){
        if(count == maxW){
            return true;
        }
        else  {
            count++;
            return false;
        }
    }
};
