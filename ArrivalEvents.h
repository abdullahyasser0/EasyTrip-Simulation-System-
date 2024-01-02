#pragma once

#include "Events.h"
class ArrivalEvents : public Events {
private:
		Passenger* passenger;
public:
	ArrivalEvents() : Events() {
		ID=0, STRT=0, END=0;
		PassengerType = "non";
		Priority = "non";
		Hours = 0, Minutes = 0;
		passenger = nullptr;

	}

	ArrivalEvents(char etype,string ptype, string priority, int id,int strt,int end,int hours,int mins,int OnoffTime) : Events() {
		PassengerType = ptype;
		ID = id, STRT = strt, END = end;
		Hours = hours;
		Minutes = mins;		
		if(!priority.empty()){
		Priority = priority;
		}else{
			Priority = "Normal";
		}
		passenger = nullptr;
		OnOffTime=OnoffTime;
		EventType=etype;

	}

	void execute(Stations<Nodestation*> S) override {
		passenger = new Passenger(PassengerType,ID, Hours,Minutes, STRT, END, OnOffTime, Priority);
		S.addPassenger(passenger);
		}
	
	int getHours()override{
		return Hours;
	}
	int getMinutes()override{
		return Minutes;
	}
		
	int getid ()override{
		return ID;
	}

	char getetype()override{
		return EventType;
	}
};