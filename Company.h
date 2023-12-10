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

public:
    Company() {
        ifstream input("input.txt");

            input >> numStations >> minsStations >> numWbuses >> numMbuses >> capacityWBus >> capacityMBus 
            >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum;
            int hours, minutes;
            char colon;

            S.addStationsByNumber(numStations);
            for (int i = 0; i < EventsNum; i++) {
                char eventType;
                input >> eventType;

                if (eventType == 'A') {
                    string PType,time,priority;
                    int id, STRT, END, NumPriority;
                    input >> PType >> time >> id >> STRT >> END;
                    getline(input, priority);
                    if(priority=="Aged"){
                        NumPriority=3;
                    }else if(priority=="POD"){
                        NumPriority=2;
                    }else if(priority=="pregnant"){
                        NumPriority=1;
                    }else{
                        NumPriority=0;
                    }

                    istringstream iss(time);
                    iss >> hours >> colon >> minutes;

                    ArrivalEvents* arrivalEvent = new ArrivalEvents(PType, priority, id, STRT, END, hours, minutes,OnOffTime);
                    eventsList.Insert(arrivalEvent);
                } 
                
                else if (eventType == 'L') {    
                    string PType,time;
                    int id, STRT;

                    input >> time >> id >> STRT;

                    istringstream iss(time);
                    iss >> hours >> colon >> minutes;

                    LeaveEvents* leaveEvent = new LeaveEvents(id, STRT, hours, minutes);
                    eventsList.Insert(leaveEvent);
                }
            }

        Node<Events*>* current = eventsList.getHead();
        while (current != nullptr) {
            Events* currentEvent = current->getItem();
            if(currentEvent->execute()->getType()=="NP"||currentEvent->execute()->getType()=="WP")
            {
                S.addPassenger( currentEvent->execute());
            }

            else if(currentEvent->execute()->getType()=="SP")
            {
                S.addSpecialPassanger(currentEvent->execute());
            }
            current = current->getNext();
        }
        
        S.PrintAllStations();

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
