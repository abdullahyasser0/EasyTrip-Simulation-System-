#pragma once

#include "Events.h"

class LeaveEvents : public Events {
private:
	Passenger* passenger;
public:
	LeaveEvents() : Events() {
		ID = 0, STRT = 0;
		Hours = 0, Minutes = 0;
	}

	LeaveEvents(char etype,int id,int strt,int hours,int mins) : Events() {
		ID = id, STRT = strt;
		Hours = hours, Minutes = mins;
		EventType=etype;
	}

	void execute(Stations<Passenger*> S) override {
		passenger = new Passenger(ID,STRT,Hours,Minutes);
		S.RemovePassenger(passenger);
	} 

	int getid () override {
		return ID;
	}
	
		int getHours()override{
		return Hours;
	}
	
	int getMinutes()override{
		return Minutes;
	}

	char getetype()override{
		return EventType;
	}
};