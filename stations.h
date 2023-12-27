#pragma once
#include "dataStructures/NoramlQueue.h"
#include "dataStructures/LinkedListp.h"
#include "dataStructures/PriorityQueue.h"
#include <iostream>
#include "Buses.h"
#include "Passenger.h"
using namespace std;
template <typename N>
class Nodestation{

private:
    int Snumber; 
    LinkedListp<Passenger> NP;
    LinkedListp<Passenger> BNP;

    Queue<Passenger> WP;
    Queue<Passenger> BWP;
    
    PriorityQueue<Passenger> SP;
    PriorityQueue<Passenger> BSP;

    Queue<Bus> Ngarage;
    Queue<Bus> Wgarage;

public :
    void setSnumber(int Number){Snumber=Number;}
    int getSnumber(){return Snumber;}
    
    LinkedListp<Passenger> *getNP(){return &NP;}
    Queue<Passenger> *getWP(){return &WP;}

    LinkedListp<Passenger> *getBNP(){return &BNP;}
    Queue<Passenger> *getBWP(){return &BWP;}

    PriorityQueue<Passenger> *getSP(){return &SP;}
    PriorityQueue<Passenger> *getBSP(){return &BSP;}

    Queue<Bus> *getNgarage(){return &Ngarage;}
    Queue<Bus> *getWgarage(){return &Wgarage;}



    Nodestation(){
        Snumber  = 0;
    }

    void PrintStationInfo(){ 
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
class Stations{

public:
    int size;
    Nodestation<T>* list;
    
    Stations() {
        size=0;
        list=nullptr;
    }
    Stations(int size){
        list = new Nodestation<T>[size+1];
    }

    void addStationsByNumber(int numberOfStations)
    {
        Nodestation<T>* newArray=new Nodestation<T>[numberOfStations+1]{};
        delete[] list;
        list=newArray;
        size=numberOfStations+1;
        for (int i =0;i<=numberOfStations;i++){
            list[i].setSnumber(i);
        }
    }

 
    void display(int size){
        for(int i=0;i<size;i++){
            list[i].Snumber=i;
            cout<<list[i].Snumber<<endl;
        }
    }

    void PrintAllStations(int size) 
    {
        for (int i=0;i<size;i++)
        {
            list[i].PrintStationInfo();
        }
    }

    void addPassenger(Passenger* passenger){
        int startStation = passenger->getStartStation();
        string passengerType = passenger->getType();
        int passDrection = passDirection(passenger);
       
        if (passengerType == "NP") {
            if(passDrection==0) list[startStation].getNP()->Insert(passenger);
            else list[startStation].getBNP()->Insert(passenger);
        } else if (passengerType == "WP") {
            if(passDrection==0) list[startStation].getWP()->enqueue(passenger);
            else list[startStation].getBWP()->enqueue(passenger);
        }else if (passengerType == "SP") {
            if(passDrection==0) list[startStation].getSP()->enqueue(passenger);
            else list[startStation].getBSP()->enqueue(passenger);        
            }

    }

    void storeNBus(Bus* bus)
    {
        list[0].getNgarage()->enqueue(bus);

    }

    void storeWBus(Bus* bus)
    {
            list[0].getWgarage()->enqueue(bus);

    }


    int passDirection(Passenger* passenger){
        int start = passenger->getStartStation();
        int end = passenger->getEndStation();
        if ((end-start)>0) return 0;
        else return 1;
    }
    
    void RemovePassenger(Passenger* passenger, int stationNumber){ // This function is used for the leave evvent
        int passDrection = passDirection(passenger);
        //int startStation = passenger->getStartStation();
        if(passDrection==0) list[stationNumber].getNP()->RemovePassenger(passenger);
        else list[stationNumber].getBNP()->RemovePassenger(passenger);
    }

    int getStationSize(){
        return size;
    }

    // void printQueue() const {
    //     PriorityNode<T>* current = front;
    //     while (current != nullptr) {
    //         cout << "[ " << current->getItem()->getID() << " ]";
    //         cout << "--->";

    //         current = current->getNext();
    //     }
    //     cout << "*\n";
    // }

    // void moveToNextStation() {
    //     currentStation++;
    // }

};
