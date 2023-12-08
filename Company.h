#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrivalEvents.h"
#include "LeaveEvents.h"
#include "LinkedList.h"
using namespace std;

class Company {
private:
    int numStations, minsStations;
    int numWbuses, numMbuses, capacityWBus, capacityMBus;
    int CheckupTrips, checkupDWBus, checkupDMBus;
    int MaxW, OnOffTime, EventsNum;
    LinkedList<Events*> eventsList;

public:
    Company() {
        ifstream input("input.txt");

            input >> numStations >> minsStations >> numWbuses >> numMbuses >> capacityWBus >> capacityMBus 
            >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum;

            cout << "events: " << EventsNum << endl;

            for (int i = 0; i < EventsNum; i++) {
            char eventType;
            input >> eventType;

            if (eventType == 'A') {
                string PType,time;
                int id, STRT, END, hours, mins;
                input >> PType >> time >> id >> STRT >> END;

                ArrivalEvents* arrivalEvent = new ArrivalEvents(PType, "no", id, STRT, END, 0, 0);
                eventsList.Insert(arrivalEvent);
            } else if (eventType == 'L') {    
                string PType,time;
                int id, STRT, hours, mins;

                input >> time >> id >> STRT;

                LeaveEvents* leaveEvent = new LeaveEvents(id, STRT, hours, mins);
                eventsList.Insert(leaveEvent);
            }
        }

        input.close();
        }

        void printEvent(){
            eventsList.PrintList();
        }

        LinkedList<Events*>& getEventsList() {
        return eventsList;
    }
        ~Company() {
        eventsList.DeleteAll();
    }
};
