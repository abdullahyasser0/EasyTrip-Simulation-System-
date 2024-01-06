#pragma once
#include <cstdlib>  

#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrivalEvents.h"
#include "LeaveEvents.h"
#include "stations.h"
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
    LinkedListp<Bus> CheckupBusses;
    LinkedListp<Passenger*> finishedPass;


public:
    Company() {
        ReadInput();
        EventList();
        int countDeqBus=0;
        char deqType= 'N';
        for(int h=0;h<24;h++){
            for(int m=0;m<60;m++){
                Nodep<Bus>* currentCheckupBus = CheckupBusses.getHead();
                Nodep<Bus>* prevCheckupBus = nullptr;
                while (currentCheckupBus != nullptr)
                {
                    if (currentCheckupBus->getItem()->finishCheckup())
                    {
                        boardingBusses.Insert(currentCheckupBus->getItem());
                        
                        if (prevCheckupBus == nullptr)
                        {
                            CheckupBusses.DeleteFirst();
                            currentCheckupBus = CheckupBusses.getHead();
                        }
                        else
                        {
                            prevCheckupBus->setNext(currentCheckupBus->getNext());
                            delete currentCheckupBus;
                            currentCheckupBus = prevCheckupBus->getNext();
                        }
                    }
                    else
                    {
                        prevCheckupBus = currentCheckupBus;
                        currentCheckupBus = currentCheckupBus->getNext();
                    }
                }
                countDeqBus++;
                S.passPromote(MaxW);
                if (h>=4 && countDeqBus%15==0){
                    countDeqBus = 0;
                    if (deqType == 'N') {
                        if(!S.list[0].getNgarage()->isEmpty()){
                            boardingBusses.Insert(S.dequeueStationZ(deqType));
                            deqType = 'W';
                        }else{
                            deqType = 'W';  
                            boardingBusses.Insert(S.dequeueStationZ(deqType));
                        }
                    } else if (deqType == 'W') {
                        if(!S.list[0].getWgarage()->isEmpty()){
                            boardingBusses.Insert(S.dequeueStationZ(deqType));
                            deqType = 'N';
                        }
                        else if(!S.list[0].getNgarage()->isEmpty()){
                            deqType = 'N';  
                            boardingBusses.Insert(S.dequeueStationZ(deqType));
                        }
                    }
                }
                while (!eventsQueue.isEmpty() && h == eventsQueue.getfront()->data->getHours() && m == eventsQueue.getfront()->data->getMinutes())
                {
                    Events* currentEvent = eventsQueue.dequeue();

                    if (currentEvent->getetype() == 'A')
                    {
                        cout << "Passenger with ID: " << currentEvent->getid() << " reached station "<<currentEvent->getSTRT()<< " at : " << h << ":" << m << endl;
                        currentEvent->execute(S);
                    }
                    else if (currentEvent->getetype() == 'L')
                    {
                        currentEvent->execute(S);
                    }

                }
                //boardingBusses.PrintBus();
 
                S.checkBoardingList(boardingBusses,minsStations);
                S.checkStations(boardingBusses,CheckupBusses);
                //boardingBusses.PrintBus();


            }
            int *arr = new int[numStations];
            if ( h >= 22 && h < 4){
                for (int i = 0; i <= numStations; i++) {
                    arr[i] += S.list[i].getNP()->getQSize();
                    delete S.list[i].getNP();

                    arr[i] += S.list[i].getBNP()->getQSize();
                    delete S.list[i].getBNP();

                    arr[i] += S.list[i].getBSP()->getSize();
                    delete S.list[i].getBSP();

                    arr[i] += S.list[i].getBWP()->getQSize();
                    delete S.list[i].getBWP();

                    arr[i] += S.list[i].getSP()->getSize();
                    delete S.list[i].getSP();

                    arr[i] += S.list[i].getWP()->getQSize();
                    delete S.list[i].getWP();                   
                }
            }
            // handling the off hours  0-numstations
                // loop over the stations when hours = 22 --done
                    // for each station get all passanger list that are not empty  --done
                    // create a counter --done
                    // delete all passanger in the non empty waiting listsand counts them --done

                    // if a bus is empty at any station it should return to station 0

                
            


        }       
                cout<<"+++++++++++++++++++++++++++"<<endl;
                CheckupBusses.PrintBus();
                cout<<"+++++++++++++++++++++++++++"<<endl;
                cout<<"BOARDING BUSES"<<endl;
                boardingBusses.PrintBus();
                cout<<"+++++++++++++++++++++++++++"<<endl;

                //S.busMoving(); 

                // S.PrintAllStations(numStations+1);
                // cout<<"+++++++++++++++++++++++++++"<<endl;
                S.PrintAllStations(numStations+1);
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
        ifstream input("random_file.txt");
        input >> numStations >> minsStations >> numWbuses >> numNbuses >> capacityWBus >> capacityNBus
            >> CheckupTrips >> checkupDWBus >> checkupDMBus >> MaxW >> OnOffTime >> EventsNum ;

        S.setOnOff(OnOffTime);
        S.addStationsByNumber(numStations);
        for (int i = 0; i < numNbuses; i++) {
            Bus* bus=new Bus(i+1,"Normal",capacityNBus,0,minsStations);
            bus->setCheckuptripsAndDuration(CheckupTrips,checkupDMBus);
            S.storeNBus(bus);
        }

        for (int i = 0; i < numWbuses; i++) {
            Bus* bus=new Bus(i+1,"Wheel",capacityNBus,0,minsStations);
            bus->setCheckuptripsAndDuration(CheckupTrips,checkupDWBus);
            S.storeWBus(bus);
        }
        input.close();
    }

    void EventList() {
        ifstream input("random_file.txt");
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