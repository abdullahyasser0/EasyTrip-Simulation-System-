#include <cstddef>
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
    int numWbuses, numNbuses, capacityWBus, capacityNBus;
    int CheckupTrips, checkupDWBus, checkupDMBus;
    int MaxW, OnOffTime, EventsNum;
    LinkedList<Events*> eventsList;
    StationsDLL<Passenger*> S;
    Bus buses;
    int hours, minutes;
    char colon,eventType;


public:
    Company() {
        ReadInput();
        EventList();
        for(int h=0;h<24;h++){
            for(int m=0;m<60;m++){
                while(eventsList.getHead()!=nullptr&&h==eventsList.getHead()->getItem()->getHours()&&m==eventsList.getHead()->getItem()->getMinutes())
                {    
                    if(eventsList.getHead()->getItem()->getetype()=='A')
                    {
                        Node<Events*>* current = eventsList.getHead();
                        Events* currentEvent = current->getItem();
                        cout<<"Passenger with ID: "<< currentEvent->getid()<<" reached the station at : "<<h<<":"<<m<<endl;
                        S.addPassenger(currentEvent->execute());
                        eventsList.DeleteFirst();
                    }else if(eventsList.getHead()->getItem()->getetype()=='L')
                    {
                        Node<Events*>* current = eventsList.getHead();
                        Events* currentEvent = current->getItem();
                        cout<<"Passenger with ID: "<< currentEvent->getid()<<" left the station at : "<<h<<":"<<m<<endl;
                        S.RemovePassenger(currentEvent->execute());
                        eventsList.DeleteFirst();
                    }
                }
            }
        }
                            S.PrintAllStations();

    }

    void ReadInput() {
        ifstream input("input.txt");
        input >> numStations >> minsStations >> numWbuses >> numNbuses >> capacityWBus >> capacityNBus
              >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum ;
        
        S.addStationsByNumber(numStations);
        for (int i = 0; i < numNbuses; i++) {
            Bus* bus=buses.createNBus(capacityNBus);
            bus->setType("Normal");
            S.storeNBus(bus);
        }

        for (int i = 0; i < numWbuses; i++) {
            Bus* bus=buses.createWBus(capacityWBus);
            bus->setType("Wheel");
            S.storeWBus(bus);
        }
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

                ArrivalEvents* arrivalEvent = new ArrivalEvents(eventType,PType, priority, id, STRT, END, hours, minutes, OnOffTime);

                eventsList.Insert(arrivalEvent);
            } else if (eventType == 'L') {
                input >> time >> id >> STRT;

                istringstream iss(time);
                iss >> hours >> colon >> minutes;

                LeaveEvents* leaveEvent = new LeaveEvents(eventType,id, STRT, hours, minutes);
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
