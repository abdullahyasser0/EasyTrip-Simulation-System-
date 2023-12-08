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
            int hours, minutes;
            char colon;

            cout << "events: " << EventsNum << endl;

            for (int i = 0; i < EventsNum; i++) {
            char eventType;
            input >> eventType;

            if (eventType == 'A') {
                string PType,time,priority;
                int id, STRT, END, hours, mins;
                input >> PType >> time >> id >> STRT >> END;
                getline(input, priority);

                istringstream iss(time);
                iss >> hours >> colon >> minutes;

                ArrivalEvents* arrivalEvent = new ArrivalEvents(PType, priority, id, STRT, END, hours, minutes,OnOffTime);
                eventsList.Insert(arrivalEvent);
            } else if (eventType == 'L') {    
                string PType,time;
                int id, STRT, hours, mins;

                input >> time >> id >> STRT;

                istringstream iss(time);
                iss >> hours >> colon >> minutes;

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
