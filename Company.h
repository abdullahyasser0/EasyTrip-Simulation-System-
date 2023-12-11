#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrivalEvents.h"
#include "LeaveEvents.h"
#include "LinkedList.h"
#include "stations.h"
using namespace std;

class Company {
private:
    int numStations, minsStations;
    int numWbuses, numMbuses, capacityWBus, capacityMBus;
    int CheckupTrips, checkupDWBus, checkupDMBus;
    int MaxW, OnOffTime, EventsNum;
    LinkedList<Events*> eventsList;
    StationsDLL<Passenger*> S;
    int hours, minutes;
    char colon,eventType;


public:
    Company() {
        ReadInput();
        EventList();
        for(int hours=0;hours<24;hours++){
            for(int minutes=0;minutes<60;minutes++){
                while(hours==eventsList.getHead()->getItem()->getHours()&&minutes==eventsList.getHead()->getItem()->getMinutes()){
                    Node<Events*>* current = eventsList.getHead();
                    Events* currentEvent = current->getItem();
                    cout<<"Passenger with ID: "<< currentEvent->getid()<<" reached the station at : "<<hours<<":"<<minutes<<endl;
                    S.addPassenger(currentEvent->execute());
                    eventsList.DeleteFirst();
                }

            }
        }
    }

    void ReadInput() {
        ifstream input("input.txt");
        input >> numStations >> minsStations >> numWbuses >> numMbuses >> capacityWBus >> capacityMBus
              >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum ;

        S.addStationsByNumber(numStations);
        input.close();
    }

    void EventList() {
        ifstream input("input.txt");
        string PType, time, priority;
        int id, STRT, END;

        for(int i=0; i < 12;i++){
            int temp;
            input >> temp;
        }

        for (int i = 0; i < EventsNum; i++) {
            input >> eventType;
            if (eventType == 'A') {
                input >> PType >> time >> id >> STRT >> END;
                getline(input, priority);
                istringstream iss(time);
                iss >> hours >> colon >> minutes;

                ArrivalEvents* arrivalEvent = new ArrivalEvents(PType, priority, id, STRT, END, hours, minutes, OnOffTime);

                eventsList.Insert(arrivalEvent);
            } else if (eventType == 'L') {
                input >> time >> id >> STRT;

                istringstream iss(time);
                iss >> hours >> colon >> minutes;

                LeaveEvents* leaveEvent = new LeaveEvents(id, STRT, hours, minutes);
                eventsList.Insert(leaveEvent);
            }
        }

        input.close();
    }

    void ExecuteEvents() {
        Node<Events*>* current = eventsList.getHead();
        while (current != nullptr) {
            Events* currentEvent = current->getItem();
            S.addPassenger(currentEvent->execute());
            current = current->getNext();
        }
        S.PrintAllStations();
    }

    ~Company() {
        eventsList.DeleteAll();
    }
};
