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
		Priority = priority;
		ID = id, STRT = strt, END = end;
		Hours = hours;
		Minutes = mins;
	}

	void execute() override {
		cout << "Arrival Event" << endl;
	}
};