#pragma once
#include "dataStructures/NoramlQueue.h"
#include "dataStructures/LinkedListp.h"
#include "dataStructures/PriorityQueue.h"
#include "Buses.h"
#include "Passenger.h"

#include <iostream>
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
    
    Stations();
    Stations(int size);

    void addStationsByNumber(int numberOfStations);
    void display(int size);
    void PrintAllStations(int size);
    void addPassenger(Passenger* passenger);
    void storeNBus(Bus* bus);
    void storeWBus(Bus* bus);
    int passDirection(Passenger* passenger);
    void RemovePassenger(Passenger* passenger, int stationNumber);
    int getStationSize();

    // void printQueue(Queue* queue) const {
    //     PriorityNode<T>* current = front;
    //     while (current != nullptr) {
    //         cout << "[ " << current->getItem()->getID() << " ]";
    //         cout << "--->";

    //         current = current->getNext();
    //     }
    //     cout << "*\n";
    // }


};
#include "stations.cpp"