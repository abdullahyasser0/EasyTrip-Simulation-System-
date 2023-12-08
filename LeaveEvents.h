#include "Events.h"

class LeaveEvents : public Events {
	LeaveEvents() : Events() {
		ID = 0, STRT = 0;
		Hours = 0, Minutes = 0;
	}

	LeaveEvents(int id,int strt,int hours,int mins) : Events() {
		ID = id, STRT = strt;
		Hours = hours, Minutes = mins;
	}

	void execute() override {
		cout << "Leave Event" << endl;
	}
};