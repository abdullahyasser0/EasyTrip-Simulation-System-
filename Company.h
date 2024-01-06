#pragma once
#include <cstdlib>  
#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrivalEvents.h"
#include "LeaveEvents.h"
#include "stations.h"
#include "UI.h"
using namespace std;
class Company {
private:
    int numStations, minsStations;
    int numWbuses, numNbuses, capacityWBus, capacityNBus;
    int CheckupTrips, checkupDWBus, checkupDMBus;
    int MaxW, OnOffTime, EventsNum;
    Queue<Events> eventsQueue;
    Stations<Nodestation*> S;
    //Bus buses;
    int hours, minutes;
    char colon,eventType;
    LinkedListp<Bus> boardingBusses;
    LinkedListp<Passenger*> finishedPass;
    char input;
    UIcla ui;

public:
    
    Company() {
        ReadInput();
        EventList();
        int countDeqBus=0;
        char deqType= 'N';
        for(int h=4;h<6;h++){
            for(int m=0;m<60;m++){
                countDeqBus++;
                //S.passPromote(MaxW);
                //S.moveBus();
                //S.busMoving();
                if (h>=4 && countDeqBus%15==0){
                    countDeqBus = 0;
                    if (deqType == 'N'&& !S.list[0].getNgarage()->isEmpty()  ) {
                        boardingBusses.Insert(S.dequeueStationZ(deqType));
                        deqType = 'W';
                    } else if (deqType == 'W'&& !S.list[0].getWgarage()->isEmpty()) {
                        boardingBusses.Insert(S.dequeueStationZ(deqType));
                        deqType = 'N';
                    }
                }
                while (!eventsQueue.isEmpty() && h == eventsQueue.getfront()->data->getHours() && m == eventsQueue.getfront()->data->getMinutes())
                {
                    Events* currentEvent = eventsQueue.dequeue();

                    if (currentEvent->getetype() == 'A')
                    {
                        cout << "Passenger with ID: " << currentEvent->getid() << " reached the station at : " << h << ":" << m << endl;
                        currentEvent->execute(S);
                    }
                    else if (currentEvent->getetype() == 'L')
                    {
                        cout << "Passenger with ID: " << currentEvent->getid() << " left the station at : " << h << ":" << m << endl;
                        currentEvent->execute(S);
                        
                    }

                }
                
                S.checkBoardingList(boardingBusses,numStations-1);
                S.checkStations(boardingBusses);
                ui.runInteractiveMode(S,numStations,h,m);
                //cout<<"@hour : "<<h<<" min : "<<m<<endl;
                //S.list[1].getNgarage()->printBusQueue();
            }

        }           
                //S.PrintAllStations(numStations+1);
    }
    Stations<Nodestation*> returnStation(){
        return S;
    }
    char getchar(){
        return input;
    }
    void PrintWaitingPassengers(){
        for(int i =0;i<numStations+1;i++){
            cout << "Waiting passengers at Station #" << S.list[i].getSnumber()<< ":" << endl;
            cout << "   NP (Forward): ";
            S.list[i].getNP()->printQueue();
            cout << "   NP (Backward): ";
            S.list[i].getBNP()->printQueue();

            cout << "   WP (Forward): ";
            S.list[i].getWP()->printQueue();
        
            cout << "   WP (Backward): ";
            S.list[i].getBWP()->printQueue();

            cout << "   SP (Forward): ";
            S.list[i].getSP()->printQueue();
        
            cout << "   SP (Backward): ";
            S.list[i].getBSP()->printQueue();

            cout << "-------------------------------------------------" << endl;
        }
    }



    // to return the current hours 
    int getCurrentHour(){
        return hours;
    }
    int getCurrentMinute()
    {
        return minutes;
    }


    void ReadInput() {
        ifstream input("input.txt");
        input >> numStations >> minsStations >> numWbuses >> numNbuses >> capacityWBus >> capacityNBus
            >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum ;
        
        S.addStationsByNumber(numStations);
        for (int i = 0; i < numNbuses; i++) {
            Bus* bus=new Bus("Normal",capacityNBus,0,minsStations);
            S.storeNBus(bus);
        }

        for (int i = 0; i < numWbuses; i++) {
            Bus* bus=new Bus("Wheel",capacityNBus,0,minsStations);
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