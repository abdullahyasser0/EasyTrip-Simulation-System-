#pragma once
#include "dataStructures/NoramlQueue.h"
#include "dataStructures/LinkedListp.h"
#include "dataStructures/PriorityQueue.h"
#include "Buses.h"
#include "Passenger.h"

#include <iostream>
using namespace std;
// template <typename N>
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

/*
PassAdd: adds a new passenger to appropriate waiting list (call it by Arrival event) -->>Done
PassRemove: removes a passenger who wants to leave (call it by leave event) -->Done
PassPromote: Promoes maxW NP to SP
BusAdd: adds a bus to the boarding buses list
BusBoarding: Uses function of Bus (GetPassOff, GetPassOn)
BusLeave: Moves a bus from station to the Moving buses (through company class)
PassFinish: moves a finished Pass. to finished List (thro. Company)
*/

/*
TODO
PassPromote: Promoes maxW NP to SP
BusAdd: adds a bus to the boarding buses list
PassFinish: moves a finished Pass. to finished List (thro. Company)
*/
template <typename T>
class Stations{

public:
    int size;
    Nodestation* list;
    
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
    void moveBus();
    // void moveNBus();
    // void moveWBus();
    void dequeueStationZ(char C);
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


template<typename T>
Stations<T>::Stations() {
    size = 0;
    list = nullptr;
}

template<typename T>
Stations<T>::Stations(int size){
    list = new Nodestation[size+1];
}
template<typename T>
void Stations<T>::addStationsByNumber(int numberOfStations)
{
    Nodestation* newArray=new Nodestation[numberOfStations+1]{};
    delete[] list;
    list=newArray;
    size=numberOfStations+1;
    for (int i =0;i<=numberOfStations;i++){
        list[i].setSnumber(i);
    }
}

template<typename T>
void Stations<T>::display(int size){
    for(int i=0;i<size;i++){
        list[i].Snumber=i;
        cout<<list[i].Snumber<<endl;
    }
}
template<typename T>
void Stations<T>::PrintAllStations(int size) 
{
    for (int i=0;i<size;i++)
    {
        list[i].PrintStationInfo();
    }
}
template<typename T>
void Stations<T>::addPassenger(Passenger* passenger){
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
template<typename T>

void Stations<T>::storeNBus(Bus* bus)
{
    list[0].getNgarage()->enqueue(bus);
}
template<typename T>
void Stations<T>::storeWBus(Bus* bus)
{
        list[0].getWgarage()->enqueue(bus);

}

template<typename T>
int Stations<T>::passDirection(Passenger* passenger){
    int start = passenger->getStartStation();
    int end = passenger->getEndStation();
    if ((end-start)>0) return 0;
    else return 1;
}
template<typename T>
void Stations<T>::RemovePassenger(Passenger* passenger, int stationNumber){ // This function is used for the leave evvent
    int passDrection = passDirection(passenger);
    //int startStation = passenger->getStartStation();
    if(passDrection==0) list[stationNumber].getNP()->RemovePassenger(passenger);
    else list[stationNumber].getBNP()->RemovePassenger(passenger);
}
template<typename T>
int Stations<T>::getStationSize(){
    return size;
}


template<typename T>
void Stations<T>::dequeueStationZ(char C){
    
    if(C=='N'&&list[0].getNgarage()->getQSize()!=0){
        list[1].getNgarage()->enqueue(list[0].getNgarage()->dequeue());
    }
    if(C=='W'&&list[0].getWgarage()->getQSize()!=0)list[1].getWgarage()->enqueue(list[0].getWgarage()->dequeue());
}

template<typename T>
void Stations<T>::moveBus(){
    for(int i = 1; i < size-1; i++){
        if(!(list[i].getNgarage()->isEmpty())&& list[i].getNP()->getCount() == 0)
        {
            list[i+1].getNgarage()->enqueue(list[i].getNgarage()->dequeue());
        }
        if(!(list[i].getWgarage()->isEmpty()) && list[i].getWP()->isEmpty()){
            list[i+1].getWgarage()->enqueue(list[i].getWgarage()->dequeue());
        }
    }
}



// template<typename T>
// void Stations<T>::moveNBus(){

//     int curr = bus->currentStation();
//     list[curr++].getNgarage->enqueue(list[curr].getNgarage()->dequeue())
    
// }

// template<typename T>
// void Stations<T>::moveWBus(){
//     int curr = bus->currentStation();
//     list[curr++].getWgarage->enqueue(list[curr].getWgarage()->dequeue())
// }