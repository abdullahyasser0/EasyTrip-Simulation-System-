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
    
    PriorityQueue<Passenger> SP;
    PriorityQueue<Passenger> BSP;

    Queue<Bus> Ngarage;
    Queue<Bus> Wgarage;
    
    Queue<Bus> BNgarage;
    Queue<Bus> BWgarage;

    LinkedListp<Passenger> finishlist;

public :
    void setSnumber(int Number){Snumber=Number;}
    int getSnumber(){return Snumber;}
    
    Queue<Passenger> *getNP(){return &NP;}
    Queue<Passenger> *getWP(){return &WP;}

    Queue<Passenger> *getBNP(){return &BNP;}
    Queue<Passenger> *getBWP(){return &BWP;}

    PriorityQueue<Passenger> *getSP(){return &SP;}
    PriorityQueue<Passenger> *getBSP(){return &BSP;}

    Queue<Bus> *getNgarage(){return &Ngarage;}
    Queue<Bus> *getWgarage(){return &Wgarage;}

    Queue<Bus> *getBNgarage(){return &BNgarage;}
    Queue<Bus> *getBWgarage(){return &BWgarage;}

    LinkedListp<Passenger> *getFinishList(){return &finishlist;}

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
    cout <<"   Backword Normal Buses: "<<BNgarage.count() <<endl; 
    cout <<"   Backword Wheel Buses: " <<BWgarage.count() << endl;
    cout<<"Finish List : "<<endl;
    finishlist.PrintList();
    cout<<"-------------------------------------------------"<<endl;
    }
};

/*
PassAdd: adds a new passenger to appropriate waiting list (call it by Arrival event) -->>Done
PassRemove: removes a passenger who wants to leave (call it by leave event) -->Done
PassPromote: Promoes maxW NP to SP
BusAdd: adds a bus to the boarding buses list --Done
BusBoarding: Uses function of Bus (GetPassOff, GetPassOn)--Done
BusLeave: Moves a bus from station to the Moving buses (through company class)--Done
PassFinish: moves a finished Pass. to finished List (thro. Company)
*/

/*
TODO
PassPromote: Promoes maxW NP to SP
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
    Bus* dequeueStationZ(char C);
    void busMoving();
    void TestbusMoving();
    void printBusesAtStation(int stationNumber);
    void checkBoardingList(LinkedListp<Bus>&busList,int STS);
    void checkStations(LinkedListp<Bus>&busList);
    void printINCheckUpBuses();
    void printFinishedPassengers();
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
        if(passDrection==0) list[startStation].getSP()->enqueue(passenger,passenger->getPriority());
        else list[startStation].getBSP()->enqueue(passenger,passenger->getPriority());        
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
            list[0].getNgarage()->peek()->setNextStation(2);
            list[0].getNgarage()->peek()->setCurrentStation(1);
            return list[0].getNgarage()->dequeue();
        }

        if(C=='W' && list[0].getWgarage()->getQSize() != 0){
            list[0].getWgarage()->peek()->setNextStation(2);
            list[0].getWgarage()->peek()->setCurrentStation(1);
            return list[0].getWgarage()->dequeue();
        }
    return nullptr;
}

template<typename T>
void Stations<T>::checkBoardingList(LinkedListp<Bus>&busList,int STS){
    Nodep<Bus>* temp=busList.getHead();
    Nodep<Bus>* prev = nullptr;
    if(!busList.isEmpty()){
        while (temp!=nullptr)
        {   
            int direction = temp->getItem()->getDirection();
            int current=temp->getItem()->getCurrentStation();
            int Movingmins = temp->getItem()->getMovingmins();
            int next = temp->getItem()->getNextStation();
            string type = temp->getItem()->getType();
            if (Movingmins != STS) temp->getItem()->plusMoviMins();

            if (Movingmins == STS) {
                Nodep<Bus>* enq = temp;
                Nodep<Bus>* del = temp;
                if (type == "Normal" ) {
                    if(direction==0)list[current].getNgarage()->enqueue(enq->getItem());
                    if(direction==1)list[current].getBNgarage()->enqueue(enq->getItem());
                } 
                if(type == "Wheel" ) {
                    if(direction==0){list[current].getWgarage()->enqueue(enq->getItem());}
                    if(direction==1){list[current].getBWgarage()->enqueue(enq->getItem());}
                }
                temp = temp->getNext();
                busList.deletenode(del);
            }
            if(temp!=nullptr){
            temp=temp->getNext();
            }
            
        }
    }
    
}


template<typename T>
void Stations<T>::checkStations(LinkedListp<Bus>&busList){
    for (int i=1; i<size;i++){
        //get passanger off
        if(!(list[i].getNgarage()->isEmpty())&&!(list[i].getNgarage()->peek()->getInBusPass().isEmpty())){
            while (list[i].getNgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getNgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
              list[i].getFinishList()->Insert(list[i].getNgarage()->peek()->getPassOff());  
            }
        }
        if(!(list[i].getBNgarage()->isEmpty())&&!(list[i].getBNgarage()->peek()->getInBusPass().isEmpty())){
            list[i].getBNgarage()->printBusQueue();
            while (list[i].getBNgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getBNgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
              list[i].getFinishList()->Insert(list[i].getBNgarage()->peek()->getPassOff());  
            }
        }
        //wheel bus

        if(!(list[i].getWgarage()->isEmpty())&&!(list[i].getWgarage()->peek()->getInBusPass().isEmpty())){
            while (list[i].getWgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getWgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
              list[i].getFinishList()->Insert(list[i].getWgarage()->peek()->getPassOff());  
            }
        }

        if(!(list[i].getBWgarage()->isEmpty())&&!(list[i].getBWgarage()->peek()->getInBusPass().isEmpty())){
            while (list[i].getBWgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getBWgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
              list[i].getFinishList()->Insert(list[i].getBWgarage()->peek()->getPassOff());  
            }
        }
        
        //get pass on
        //Np
        while (!(list[i].getSP()->isEmpty())&&!(list[i].getNgarage()->isEmpty()) )
        {
            Passenger *Spass = list[i].getSP()->returnHead()->getItem();
            list[i].getNgarage()->getfront()->data->getPassOn(Spass);
            list[i].getSP()->dequeue();
        }
        while (!(list[i].getNP()->isEmpty())&&!(list[i].getNgarage()->isEmpty()) )
        {
            Passenger *pass = list[i].getNP()->returnHead()->data;
            list[i].getNgarage()->getfront()->data->getPassOn(pass);
            list[i].getNP()->dequeue();

        }

        while (!(list[i].getBSP()->isEmpty())&&!(list[i].getBNgarage()->isEmpty()) )
        {
            Passenger *Spass = list[i].getBSP()->returnHead()->getItem();
            list[i].getBNgarage()->getfront()->data->getPassOn(Spass);
            list[i].getBSP()->dequeue();
        }
        while (!(list[i].getBNP()->isEmpty())&&!(list[i].getBNgarage()->isEmpty()))
        {
            Passenger *pass = list[i].getBNP()->returnHead()->data;
            list[i].getBNgarage()->getfront()->data->getPassOn(pass);
            list[i].getBNP()->dequeue();

        }
        
        // wheel
        while (!(list[i].getWP()->isEmpty())&&!(list[i].getWgarage()->isEmpty()))
        {
            Passenger *pass = list[i].getWP()->returnHead()->data;
            list[i].getWgarage()->getfront()->data->getPassOn(pass);
            list[i].getWP()->dequeue();

        }
        while (!(list[i].getBWP()->isEmpty())&&!(list[i].getBWgarage()->isEmpty()))
        {
            Passenger *pass = list[i].getBWP()->returnHead()->data;
            list[i].getBWgarage()->getfront()->data->getPassOn(pass);
            list[i].getBWP()->dequeue();

        }


        
        //buss leaves to the boarding list
        if(!(list[i].getNgarage()->isEmpty())){
        list[i].getNgarage()->peek()->gnextStation(size-1);
        //if(list[i].getNgarage()->peek()->getNextStation()==size-1){list[i].getNgarage()->peek()->setDirection(1);}
        busList.Insert(list[i].getNgarage()->dequeue());
        }

        if(!(list[i].getBNgarage()->isEmpty())){
        list[i].getBNgarage()->peek()->gnextStation(size-1);
        busList.Insert(list[i].getBNgarage()->dequeue());
        }
        //wheel


        if(!(list[i].getWgarage()->isEmpty())){
        list[i].getWgarage()->peek()->gnextStation(size-1);
        busList.Insert(list[i].getWgarage()->dequeue());
        }

        if(!(list[i].getBWgarage()->isEmpty())){
        list[i].getBWgarage()->peek()->gnextStation(size-1);
        busList.Insert(list[i].getBWgarage()->dequeue());
        }

    }
}







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
            list[i].getSP()->enqueue(list[i].getNP()->dequeue(),3);
        }
        if(list[i].getBNP()->peek()!=nullptr &&list[i].getBNP()->peek()->hasReachedMaxTime(maxW)){
            list[i].getBSP()->enqueue(list[i].getBNP()->dequeue(),3);
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

    int waitingWP = forwardWP->count() + backwardWP->count();
    int waitingNP = forwardNP->count() + backwardNP->count();
    
    cout << waitingWP << " waiting WP: FWD[";
    if (!forwardWP->isEmpty()) {
        forwardWP->printQueue();
        cout << "] ";
    }

    cout << " BCK[";
    if (!backwardWP->isEmpty()) {
        backwardWP->printQueue();
        cout << "]" << endl;
    }

    cout << waitingNP << " waiting NP: FWD[";
    if(!forwardNP->isEmpty()){
        forwardNP->printQueue();
        cout << "] ";
    }
    cout << "BCK[";
    if(!backwardNP->isEmpty()){
        backwardNP->printQueue();
        cout << "]" << endl;
    }
}


// // template<typename T>
// // void Stations<T>::printINCheckUpBuses() {
// //     cout << "In-Checkup buses: ";
    
// //     for (int i = 0; i < ; ++i) {
// //         if (!list[i].getNgarage()->isEmpty()) {
// //             Bus* bus = list[i].getNgarage()->peek();
// //             if (bus->isInCheckUp()) {
// //                 cout << bus->getBusID() << ", ";
// //             }
// //         }
// //         if (!list[i].getWgarage()->isEmpty()) {
// //             Bus* bus = list[i].getWgarage()->peek();
// //             if (bus->isInCheckUp()) {
// //                 cout << bus->getBusID() << ", ";
// //             }
// //         }
// //     }

// //     cout << endl;
// // }


template<typename T>
void Stations<T>::printBusesAtStation(int stationNumber) {
    int ngarage = list[stationNumber].getNgarage()->count();
    int wgarage = list[stationNumber].getWgarage()->count();
    int waitingBuses = ngarage + wgarage;

    if (waitingBuses > 0) {
        cout << waitingBuses << " buses waiting at this station:" << endl;
        
        Bus* bus = list[stationNumber].getNgarage()->peek();
        cout << bus->getType() << "[" << bus->getDirection() << "," << bus->getCapacity() << "] {";

        PriorityQueue<Passenger> inBusPass = bus->getInBusPass();
        while (!inBusPass.isEmpty()) {
            Passenger* passengerPtr = inBusPass.dequeue();  
            Passenger passenger = *passengerPtr;
            cout << passenger.getID();
            if (!inBusPass.isEmpty()) {
                cout << ", ";
            }
        }

        cout << "}" << endl;
        cout << "------------------------------------------------------" << endl;
    }
}

template<typename T>
void Stations<T>::printFinishedPassengers() {
    cout << "Finished passengers: ";

    for (int i = 0; i < size; ++i) {
        LinkedListp<Passenger>* finishList = list[i].getFinishList();
        Nodep<Passenger>* current = finishList->getHead();

        while (current != nullptr) {
            cout << current->getItem()->getID();
            if (current->getNext() != nullptr) {
                cout << ", ";
            }
            current = current->getNext();
        }
    }

    cout << endl;
}



