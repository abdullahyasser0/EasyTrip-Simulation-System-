#pragma once
#include "dataStructures/Stack.h"
#include "dataStructures/NoramlQueue.h"
#include "dataStructures/LinkedListp.h"
#include "dataStructures/PriorityQueue.h"
#include <iostream>
using namespace std;

template <typename N>
class Nodestation{

public :
    Nodestation<N>* next;
    Nodestation<N>* back;
    // Queue* busstop; //buss stop
     
    //busses mantain "bayoumi says is should be on station 0 "
    
    int Snumber;

    
    LinkedListp<Passenger> NP;
    LinkedListp<Passenger> BNP;

    Queue<Passenger> WP;
    Queue<Passenger> BWP;
    
    PriorityQueue SP;
    PriorityQueue BSP;

    Queue<Bus> Ngarage;
    Queue<Bus> Wgarage;
    /*
    must add a variable for the waitiing passangers of type <queue> 
    this is the link between me and the passengers class

    how the buses and me will operate ?
    the buses will maintain <queue> , garage in station 0 <stack>, stop into the bus stops <queue> 
    */

    Nodestation(){

        next = nullptr;
        back = nullptr; 

        // busstop = nullptr; 

        Snumber  = 0;

    }

    void PrintAllstation(){
        cout<<"Station Number: "<<Snumber<<endl;
        cout<<"Forward NP list: ";
        NP.PrintList();
        cout<<"Backword NP list: ";
        BNP.PrintList();
        cout<<"Forward WP list: ";
        WP.printQueue();
        cout<<"Backword WP list: ";
        BWP.printQueue();
        cout<<"Forward SP Queue: ";
        SP.printQueue();
        cout<<"Backword SP Queue: ";
        BSP.printQueue();
        cout << "Garage: " << endl;
        cout <<"    Normal Buses: "<<Ngarage.count() <<endl; 
        cout <<"    Wheel Buses: " <<Wgarage.count() << endl;
        cout<<"-------------------------------------------------"<<endl;
    }

};


template <typename T>
class StationsDLL{

public:
    Nodestation<T>* Fstation;
    int currentStation;

    StationsDLL()
    { 
        Fstation = nullptr;
        currentStation = 0;
    }
    

    bool nostation()
    {
        return (Fstation==nullptr);
    }

    void addstation(){
        Nodestation<T>* newstation= new Nodestation<T>;

        if(nostation())
        {
            newstation->Snumber=0;
            Fstation=newstation;

        }    
        else{

            Nodestation<T>* temp=Fstation;

            while (temp->next !=nullptr)
            {
                temp=temp->next;
            }

            newstation->Snumber=temp->Snumber+1;
            temp->next=newstation;
            newstation->back=temp;
        }


    }
    void addStationsByNumber(int numberOfStations)
    {
        for (int i=0 ;i<numberOfStations+1 ; i++){
            addstation();
        }
    }

    Nodestation<T> *ReturnStationPointer(int stationnumber)
    {
        Nodestation<T>* temp=Fstation;
        while (temp!=nullptr)
        {
            if(temp->Snumber!=stationnumber) temp=temp->next;
            else return temp;
        }
        return nullptr;
    }

    void display()
    {
        if(!nostation()){
        Nodestation<T>* temp=Fstation;
        while (temp!=nullptr)
        {
            cout<<temp->Snumber<<endl;
            temp=temp->next;
        }
        }
    }

    void PrintAllStations() 
    {
        Nodestation<T>* temp = Fstation;
        while (temp != nullptr) 
        {
            temp->PrintAllstation();
            temp = temp->next;
        }
    }

    void addPassenger(Passenger* passenger){
        if (Fstation == nullptr) {
            return;
        }

        int startStation = passenger->getStartStation();
        Nodestation<T>* stationPtr = ReturnStationPointer(startStation);

        if (stationPtr == nullptr) 
        {
            cerr << "Error: Invalid start station for passenger."<< startStation << endl;
            return;
        }
        string passengerType = passenger->getType();
        int passDrection = passDirection(passenger);
       
        if (passengerType == "NP") {
            if(passDrection==0) stationPtr->NP.Insert(passenger);
            else stationPtr->BNP.Insert(passenger);
        } else if (passengerType == "WP") {
            if(passDrection==0) stationPtr->WP.enqueue(passenger);
            else stationPtr->BWP.enqueue(passenger);
        }else if (passengerType == "SP") {
            if(passDrection==0) stationPtr->SP.enqueue(passenger);
            else stationPtr->BSP.enqueue(passenger);        
            }

    }

    void storeNBus(Bus* bus)
    {
        Fstation->Ngarage.enqueue(bus);

    }

    void storeWBus(Bus* bus)
    {
            Fstation->Wgarage.enqueue(bus);

    }


    int passDirection(Passenger* passenger){
        int start = passenger->getStartStation();
        int end = passenger->getEndStation();
        if ((end-start)>0) return 0;
        else return 1;
    }
    
    void RemovePassenger(Passenger* passenger){
        if (Fstation == nullptr) {
            return;
        }
        int passDrection = passDirection(passenger);
        int startStation = passenger->getStartStation();
        Nodestation<T>* stationPtr = ReturnStationPointer(startStation);
        if (stationPtr == nullptr) {
            cerr << "Error: Invalid start station for passenger."<< startStation << endl;
            return;
        }
        if(passDrection==0) stationPtr->NP.RemovePassenger(passenger);
        else stationPtr->BNP.RemovePassenger(passenger);
    }
    // added functions to use it in my ui class 
    int getCurrentStation() {
        return currentStation;
    }

    void moveToNextStation() {
        currentStation++;
    }

};