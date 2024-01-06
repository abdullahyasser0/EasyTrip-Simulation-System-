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
    Queue<Passenger> NP;
    Queue<Passenger> BNP;

    Queue<Passenger> WP;
    Queue<Passenger> BWP;
    
    Queue<Passenger> SP;
    Queue<Passenger> BSP;

    Queue<Bus> Ngarage;
    Queue<Bus> Wgarage;

public :
    void setSnumber(int Number){Snumber=Number;}
    int getSnumber(){return Snumber;}
    
    Queue<Passenger> *getNP(){return &NP;}
    Queue<Passenger> *getWP(){return &WP;}

    Queue<Passenger> *getBNP(){return &BNP;}
    Queue<Passenger> *getBWP(){return &BWP;}

    Queue<Passenger> *getSP(){return &SP;}
    Queue<Passenger> *getBSP(){return &BSP;}

    Queue<Bus> *getNgarage(){return &Ngarage;}
    Queue<Bus> *getWgarage(){return &Wgarage;}


    Nodestation(){
    Snumber  = 0;
    }

    void PrintStationInfo(){ 
    cout<<"Station Number: "<<Snumber<<endl;
    cout<<"Forward NP list: ";
    NP.printQueue();
    cout<<"Backword NP list: ";
    BNP.printQueue();
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
    void passPromote(int maxWaitingTime); 
    void RemovePassenger(Passenger* passenger, int stationNumber);
    int getStationSize();
    void moveBus();
    void passPromote();
    void printWaitingSP(int stationNumber);
    void printWaitingWPandNP(int stationNumber);
    // void moveNBus();
    // void moveWBus();
    Bus* dequeueStationZ(char C);
    void busMoving();
    void TestbusMoving();
    void printBusesAtStation(int stationNumber);
    void checkBoardingList(LinkedListp<Bus>busList,int STS);
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

// template<typename T>
// void Stations<T>::display(int size){
//     for(int i=0;i<size;i++){
//         list[i].Snumber=i;
//         cout<<list[i].Snumber<<endl;
//     }
// }
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
        if(passDrection==0) list[startStation].getNP()->enqueue(passenger);
        else list[startStation].getBNP()->enqueue(passenger);
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
    if(passDrection==0) list[stationNumber].getNP()->dequeue();
    else list[stationNumber].getBNP()->dequeue();
}
template<typename T>
int Stations<T>::getStationSize(){
    return size;
}


template<typename T>
Bus* Stations<T>::dequeueStationZ(char C){
    
        if(C=='N' && list[0].getNgarage()->getQSize() != 0){
            list[0].getNgarage()->peek()->setNextStation(1);
            return list[0].getNgarage()->dequeue();
        }
        if(C=='W' && list[0].getWgarage()->getQSize() != 0){
            list[0].getWgarage()->peek()->setNextStation(1);
            return list[0].getWgarage()->dequeue();
        }
    return nullptr;
}

template<typename T>
void Stations<T>::checkBoardingList(LinkedListp<Bus>busList,int STS){
    Nodep<Bus>* temp=busList.getHead();
    if(!busList.isEmpty()){
        while (temp!=nullptr)
        {   

            int current=temp->getItem()->getMovingmins();
            int next=temp->getItem()->getNextStation();
            if(current!=STS)temp->getItem()->plusMoviMins();

            if(current==STS){
                Nodep<Bus>* enq=temp;
                list[next].getNgarage()->enqueue(enq->getItem());
                //busList.deletenode(temp); the problem is heeere 
            }
            if(temp!=nullptr){
            temp=temp->getNext();
            }
            
        }
    }
    
}
// template<typename T>
// void Stations<T>::moveBus(){
//     for(int i = 1; i <2; i++){
//         if(!(list[i].getNgarage()->isEmpty())&& list[i].getNP()->getCount() == 0)
//         {
//             list[i+1].getNgarage()->enqueue(list[i].getNgarage()->dequeue());
//         }
//         if(!(list[i].getWgarage()->isEmpty()) && list[i].getWP()->isEmpty()){
//             list[i+1].getWgarage()->enqueue(list[i].getWgarage()->dequeue());
//         }
//     }
// }

template<typename T>
void Stations<T> :: busMoving(){
    for(int i=0; i<2 ; i++){
        Bus *temp= list[i].getNgarage()->dequeue();
        temp->print_bus_info();
        list[i+1].getNgarage()->enqueue(temp);
        if(!(temp->getInBusPass().isEmpty())){
            while (temp->getInBusPass().getFront()->getItem()->getEndStation()!=i+1)
            {
                temp->getPassOff();
                
            }
        }
        while (temp->getCapacity()>0 && !(list[i+1].getNP()->isEmpty()))
        {
            Passenger *pass = list[i+1].getNP()->returnHead()->data;
            temp->getPassOn(pass);
            list[i+1].getNP()->dequeue();  
        }
    }
    
}
template<typename T>
void Stations<T>::passPromote(int maxW){
    for(int i = 0; i < size; i++){
        if(list[i].getNP()->peek()!=nullptr &&list[i].getNP()->peek()->hasReachedMaxTime(maxW)){
            list[i].getSP()->enqueue(list[i].getNP()->dequeue());
        }
        if(list[i].getBNP()->peek()!=nullptr &&list[i].getBNP()->peek()->hasReachedMaxTime(maxW)){
            list[i].getBSP()->enqueue(list[i].getBNP()->dequeue());
        }
        
    }
}




// template<typename T>
// void Stations<T>::printWaitingSP(int stationNumber) {
//     int forwardSP = list[stationNumber].getSP()->count();
//     int backwardSP = list[stationNumber].getBSP()->count();
//     int waitingSP = forwardSP + backwardSP;
//     cout << waitingSP << " waiting sp: FWD[" << forwardSP << "] BCK[" << backwardSP << "]" << endl;



//     cout << "Waiting SP: FWD[" << forwardSP << "]";
//     if (!forwardSP.isEmpty()) {
//         cout << "(";
//         forwardSP.printQueue();
//         cout << ")";
//     }

//     cout << " BCK[" << backwardSP.count() << "]";
//     if (!backwardSP.isEmpty()) {
//         cout << "{";
//         backwardSP.printQueue();
//         cout << "}";
//     }

//     cout << endl;
// }

template<typename T>
void Stations<T>::printWaitingWPandNP(int stationNumber) {
    Queue<Passenger>* forwardWP = list[stationNumber].getWP();
    Queue<Passenger>* backwardWP = list[stationNumber].getBWP();
    Queue<Passenger>* forwardNP = list[stationNumber].getNP();
    Queue<Passenger>* backwardNP = list[stationNumber].getBNP();

    cout << "Waiting WP: FWD[" << forwardWP->count() << "]";
    if (!forwardWP->isEmpty()) {
        cout << "{";
        forwardWP->printQueue();
        cout << "}";
    }

    cout << " BCK[" << backwardWP->count() << "]";
    if (!backwardWP->isEmpty()) {
        cout << "{";
        backwardWP->printQueue();
        cout << "}";
    }

    cout << endl;

    cout << "Waiting NP: FWD[" << forwardNP->count() << "]";
    if (!forwardNP->isEmpty()) {
        cout << "{";
        forwardNP->printQueue();
        cout << "}";
    }

    cout << " BCK[" << backwardNP->count() << "]";
    if (!backwardNP->isEmpty()) {
        cout << "{";
        backwardNP->printQueue();
        cout << "}";
    }

    cout << endl;
}

template <typename T>
void Stations<T>::printBusesAtStation(int stationNumber){
    int ngarage = list[stationNumber].getNgarage()->count();
    int wgarage = list[stationNumber].getWgarage()->count();
    int waitingBuses = ngarage + wgarage;
    cout << waitingBuses << " buses waiting at this station:"<< endl;
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