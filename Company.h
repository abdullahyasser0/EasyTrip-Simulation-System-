#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrivalEvents.h"
#include "LeaveEvents.h"
#include "LinkedList.h"
#include "stations.h"
using namespace std;
//lol
//lol2
class Company {
private:
    int numStations, minsStations;
    int numWbuses, numNbuses, capacityWBus, capacityNBus;
    int CheckupTrips, checkupDWBus, checkupDMBus;
    int MaxW, OnOffTime, EventsNum;
    Queue<Events> eventsQueue;
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
                while(!eventsQueue.isEmpty()&&h==eventsQueue.getfront()->data->getHours()&&m==eventsQueue.getfront()->data->getMinutes())
                {    
                    Events* currentEvent = eventsQueue.dequeue();

                    if(currentEvent->getetype()=='A')
                    {
                        cout << "Passenger with ID: " << currentEvent->getid() << " reached the station at : " << h << ":" << m << endl;
                        S.addPassenger(currentEvent->execute());
                    }else if(currentEvent->getetype()=='L')
                    {
                        cout << "Passenger with ID: " << currentEvent->getid() << " left the station at : " << h << ":" << m << endl;
                        S.RemovePassenger(currentEvent->execute());
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

                eventsQueue.enqueue(arrivalEvent);
            } else if (eventType == 'L') {
                input >> time >> id >> STRT;

                istringstream iss(time);
                iss >> hours >> colon >> minutes;
                LeaveEvents* leaveEvent = new LeaveEvents(eventType,id, STRT, hours, minutes);
                eventsQueue.enqueue(leaveEvent);
            }
        }

        input.close();
    }
};
