#include "Events.h"
class ArrivalEvents : public Events {
public:
	ArrivalEvents() : Events() {
		ID=0, STRT=0, END=0;
		PassengerType = "non";
		Priority = "non";
		Hours = 0, Minutes = 0;
	}

	ArrivalEvents(string ptype, string priority, int id,int strt,int end,int hours,int mins) : Events() {
		PassengerType = ptype;
		ID = id, STRT = strt, END = end;
		Hours = hours;
		Minutes = mins;		
		if(!priority.empty()){
		Priority = priority;
		}else{
			Priority = "Normal";
		}
	}

	void execute() override {
		cout << "Arrival Event" << endl;
	}
	int getid ()override{
		return ID;
	}
};