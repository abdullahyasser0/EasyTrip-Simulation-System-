#pragma once
#include "dataStructures/Queue.h"
#include "dataStructures/LinkedListp.h"
#include "dataStructures/PriorityQueue.h"
#include "Buses.h"
#include "Passenger.h"
#include "dataStructures/NormalQueue.h"

#include <iostream>
using namespace std;
// template <typename N>
class Nodestation{

private:
    int Snumber; 
    NormalQueue<Passenger> NP;
    NormalQueue<Passenger> BNP;

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
    
    NormalQueue<Passenger> *getNP(){return &NP;}
    Queue<Passenger> *getWP(){return &WP;}

    NormalQueue<Passenger> *getBNP(){return &BNP;}
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
    cout <<"    Normal Buses: "<<Ngarage.getQuqeCount() <<endl; 
    cout <<"    Wheel Buses: " <<Wgarage.getQuqeCount() << endl;
    cout <<"   Backword Normal Buses: "<<BNgarage.getQuqeCount() <<endl; 
    cout <<"   Backword Wheel Buses: " <<BWgarage.getQuqeCount() << endl;
    cout<<"Finish List : "<<endl;
    finishlist.PrintList();
    cout<<"-------------------------------------------------"<<endl;
    }
};

template <typename T>
class Stations{

public:
    int currentTime;
    bool Nready = true;
    bool BNready = true;
    bool Wready = true;
    bool BWready = true;
    int size;
    int getOnOff;
    int onOffSeconds=0;
    int waitingSP;
    int waitingWP;
    int waitingNP;
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
    void RemovePassenger(int ID, int stationNumber);
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
    void checkStations(LinkedListp<Bus>&busList,LinkedListp<Bus>&CheckupList,int h, int m,LinkedListp<Passenger>& finishedPass);
    void printINCheckUpBuses();
    void printFinishedPassengers(int stationNumber);
    void setOnOff(int GOF);
    void printBusses(int stationNumber);
    void printPassengerStatistics();
    void printPassengerCounts();
    void printBusCounts();    
    double calculateAutoPromotedPercentage(int maxW);
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
void Stations<T>:: setOnOff(int GOF){
    getOnOff=GOF;
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
void Stations<T>::RemovePassenger(int ID, int stationNumber){ // This function is used for the leave evvent
    if(list[stationNumber].getNP()->passengerLeave(ID)) return;
    else{
        list[stationNumber].getBNP()->passengerLeave(ID);
    }
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
void Stations<T>::checkStations(LinkedListp<Bus>&busList,LinkedListp<Bus>&CheckupList,int h,int m,LinkedListp<Passenger>& finishedPass){
    for (int i=1; i<size;i++){
        // get passanger off
        if(!(list[i].getNgarage()->isEmpty())&&!(list[i].getNgarage()->peek()->getInBusPass().isEmpty())){
            while (list[i].getNgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getNgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
              if(onOffSeconds>=60){
                onOffSeconds=0;
                Nready=false;
                break;
              }
              Passenger *pass = list[i].getNgarage()->peek()->getPassOff();
              pass->setftime(h, m);
              finishedPass.Insert(pass);
              list[i].getFinishList()->Insert(pass); 
              onOffSeconds+=getOnOff;
              Nready=true; 
            }
        }
        if(!(list[i].getBNgarage()->isEmpty())&&!(list[i].getBNgarage()->peek()->getInBusPass().isEmpty())){
            while (list[i].getBNgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getBNgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
            if(onOffSeconds>=60){
                onOffSeconds=0;
                BNready=false;
                break;
              }
              Passenger *pass = list[i].getBNgarage()->peek()->getPassOff();
              pass->setftime(h, m);
              finishedPass.Insert(pass);
              list[i].getFinishList()->Insert(pass); 
              onOffSeconds+=getOnOff;
              BNready=true; 
            }
        }
        //wheel bus

        if(!(list[i].getWgarage()->isEmpty())&&!(list[i].getWgarage()->peek()->getInBusPass().isEmpty())){
            while (list[i].getWgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getWgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
              if(onOffSeconds>=60){
                onOffSeconds=0;
                Wready=false;
                break;
              }
              Passenger *pass = list[i].getWgarage()->peek()->getPassOff();
              pass->setftime(h, m);
              finishedPass.Insert(pass);
              list[i].getFinishList()->Insert(pass);
              onOffSeconds+=getOnOff;
              Wready=true;   
            }
        }

        if(!(list[i].getBWgarage()->isEmpty())&&!(list[i].getBWgarage()->peek()->getInBusPass().isEmpty())){
            while (list[i].getBWgarage()->peek()->getInBusPass().getFront()!=nullptr&&list[i].getBWgarage()->peek()->getInBusPass().getFront()->getItem()->getEndStation()==i)
            {
              if(onOffSeconds>=60){
                onOffSeconds=0;
                BWready=false;
                break;
              }
              Passenger *pass = list[i].getBWgarage()->peek()->getPassOff();
              pass->setftime(h, m);
              finishedPass.Insert(pass);
              list[i].getFinishList()->Insert(pass); 
              onOffSeconds+=getOnOff;
              BWready=true;   
            }
        }
        
        //get pass on -----------------------------------------------------------------------------------------------
        //Np
        onOffSeconds=0;
        while (!(list[i].getSP()->isEmpty())&&!(list[i].getNgarage()->isEmpty()) )
        {
            if(list[i].getNgarage()->peek()->isFull()){
                Nready=true;
                break;
            }
            
            if(onOffSeconds>=60){
                onOffSeconds=0;
                Nready=false;
                break;
              }
            Passenger *Spass = list[i].getSP()->returnHead()->getItem();
            Spass->setWtime(h, m);
            list[i].getNgarage()->getfront()->data->getPassOn(Spass);
            list[i].getSP()->dequeue();
            onOffSeconds+=getOnOff;
            Nready=true;
        }
        onOffSeconds=0;
        while (!(list[i].getNP()->isEmpty())&&!(list[i].getNgarage()->isEmpty()) )
        {
            if(list[i].getNgarage()->peek()->isFull()){
                Nready=true;
                break;
            }
            if(onOffSeconds>=60){
                onOffSeconds=0;
                Nready=false;
                break;
              }
            Passenger *pass = list[i].getNP()->returnHead()->data;
                        pass->setWtime(h, m);
            list[i].getNgarage()->getfront()->data->getPassOn(pass);
            list[i].getNP()->dequeue();
            onOffSeconds+=getOnOff;

        }
        onOffSeconds=0;
        while (!(list[i].getBSP()->isEmpty())&&!(list[i].getBNgarage()->isEmpty()) )
        {
            if(list[i].getBNgarage()->peek()->isFull()){
                BNready=true;
                break;
            }
            if(onOffSeconds>=60){
                onOffSeconds=0;
                BNready=false;
                break;
              }
            Passenger *Spass = list[i].getBSP()->returnHead()->getItem();
                        Spass->setWtime(h, m);
            list[i].getBNgarage()->getfront()->data->getPassOn(Spass);
            list[i].getBSP()->dequeue();
            onOffSeconds+=getOnOff;

        }
        onOffSeconds=0;
        while (!(list[i].getBNP()->isEmpty())&&!(list[i].getBNgarage()->isEmpty()))
        {
            if(list[i].getBNgarage()->peek()->isFull()){
                BNready=true;
                break;
            }
            if(onOffSeconds>=60){
                onOffSeconds=0;
                BNready=false;
                break;
              }
            Passenger *pass = list[i].getBNP()->returnHead()->data;
                        pass->setWtime(h, m);
            list[i].getBNgarage()->getfront()->data->getPassOn(pass);
            list[i].getBNP()->dequeue();
            onOffSeconds+=getOnOff;

        }
        
        // wheel
        onOffSeconds=0;
        while (!(list[i].getWP()->isEmpty())&&!(list[i].getWgarage()->isEmpty()))
        {
            if(list[i].getWgarage()->peek()!=nullptr&&list[i].getWgarage()->peek()->isFull()){
                Wready=true;
                break;
            }
            if(onOffSeconds>=60){
                onOffSeconds=0;
                Wready=false;
                break;
              }
            Passenger *pass = list[i].getWP()->returnHead()->data;
            list[i].getWgarage()->getfront()->data->getPassOn(pass);
            list[i].getWP()->dequeue();
            onOffSeconds+=getOnOff;


        }
        onOffSeconds=0;
        while (!(list[i].getBWP()->isEmpty())&&!(list[i].getBWgarage()->isEmpty()))
        {
            if(list[i].getBWgarage()->peek()!=nullptr&&list[i].getBWgarage()->peek()->isFull()){
                BWready=true;
                break;
            }
            if(onOffSeconds>=60){
                onOffSeconds=0;
                BWready=false;
                break;
              }
            Passenger *pass = list[i].getBWP()->returnHead()->data;
            list[i].getBWgarage()->getfront()->data->getPassOn(pass);
            list[i].getBWP()->dequeue();
            onOffSeconds+=getOnOff;
        }

        // if(m==0&&(h==1||h==10||h==20)){
        //     cout<<"Stations at: "<<h<<" : "<<m<<endl;
        // PrintAllStations(size);
        // }

        //buss leaves to the boarding list
        if(Nready && !(list[i].getNgarage()->isEmpty())){
        list[i].getNgarage()->peek()->gnextStation(size-1);
        if(list[i].getNgarage()->peek()->Checkup()){
            CheckupList.Insert(list[i].getNgarage()->dequeue());
        }
        else
        {
            busList.Insert(list[i].getNgarage()->dequeue());
        }
        }

        if(BNready && !(list[i].getBNgarage()->isEmpty())){
        list[i].getBNgarage()->peek()->gnextStation(size-1);
        if(list[i].getBNgarage()->peek()->Checkup()){
            CheckupList.Insert(list[i].getBNgarage()->dequeue());
        }else{
        busList.Insert(list[i].getBNgarage()->dequeue());
        }
        }
        //wheel


        if(Wready && !(list[i].getWgarage()->isEmpty())){
        list[i].getWgarage()->peek()->gnextStation(size-1);
        if(list[i].getWgarage()->peek()->Checkup()){
            CheckupList.Insert(list[i].getWgarage()->dequeue());
        }else{
        busList.Insert(list[i].getWgarage()->dequeue());
        }
        }

        if(BWready && !(list[i].getBWgarage()->isEmpty())){
        list[i].getBWgarage()->peek()->gnextStation(size-1);
        if(list[i].getBWgarage()->peek()->Checkup()){
            CheckupList.Insert(list[i].getBWgarage()->dequeue());
        }else{
        busList.Insert(list[i].getBWgarage()->dequeue());
        }
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

template<typename T>
double Stations<T>::calculateAutoPromotedPercentage(int maxW) {
    int totalNormalPassengers = 0;
    int autoPromotedPassengers = 0;

    for (int i = 0; i < size; i++) {
        NormalNode<Passenger>* currentNormalPassenger = list[i].getNP()->returnHead();
        while (currentNormalPassenger != nullptr) {

            totalNormalPassengers++;

            if (currentNormalPassenger->data->hasReachedMaxTime(maxW)) {
                autoPromotedPassengers++;
            }

            currentNormalPassenger = currentNormalPassenger->next;
        }

        currentNormalPassenger = list[i].getBNP()->returnHead();
        while (currentNormalPassenger != nullptr) {
            totalNormalPassengers++;

            if (currentNormalPassenger->data->hasReachedMaxTime(maxW)) {
                autoPromotedPassengers++;
            }

            currentNormalPassenger = currentNormalPassenger->next;
        }
    }

    // Calculate and return the percentage
    if (totalNormalPassengers > 0) {
        return (static_cast<double>(autoPromotedPassengers) / totalNormalPassengers) * 100.0;
    } else {
        return 0.0; // Avoid division by zero
    }
}


template<typename T>
void Stations<T>::printWaitingSP(int stationNumber) {
    PriorityQueue<Passenger>* forwardSP = list[stationNumber].getSP();
    PriorityQueue<Passenger>* backwardSP = list[stationNumber].getBSP();
    int waitingSP = forwardSP->getSize() + backwardSP->getSize();
    cout << waitingSP <<" ";
    cout << "Waiting SP: FWD[";
    forwardSP->printSPQueue();
        cout << "]";
   

    cout << " BCK[";
    backwardSP->printSPQueue();
    cout << "]"<<endl;

}

template<typename T>
void Stations<T>::printWaitingWPandNP(int stationNumber) {
    Queue<Passenger>* forwardWP = list[stationNumber].getWP();
    Queue<Passenger>* backwardWP = list[stationNumber].getBWP();
    Queue<Passenger>* forwardNP = list[stationNumber].getNP();
    Queue<Passenger>* backwardNP = list[stationNumber].getBNP();

    waitingWP = forwardWP->getQuqeCount() + backwardWP->getQuqeCount();
    waitingNP = forwardNP->getQuqeCount() + backwardNP->getQuqeCount();
    
    
        cout << waitingWP << " waiting WP: FWD[";
        forwardWP->printQueue();
        cout << "]";

        cout << " BCK[";
        backwardWP->printQueue();
        cout << "]" << endl;

    
        cout << waitingNP << " waiting NP: FWD[";
        forwardNP->printQueue();
        cout << "]";
    
        cout << " BCK[";
        backwardNP->printQueue();
        cout << "]" << endl;
    
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
    int ngarage = list[stationNumber].getNgarage()->getQuqeCount();
    int wgarage = list[stationNumber].getWgarage()->getQuqeCount();
    int waitingBuses = ngarage + wgarage;
    cout << waitingBuses << " buses waiting at this station:" << endl;   
    if (waitingBuses > 0) {
        cout << waitingBuses << " buses waiting at this station:" << endl;
        Bus* bus = list[stationNumber].getNgarage()->peek();
        if(bus!=nullptr){
            string bDirect;
            cout<<"I BROKE HERE"<<endl;
            if(bus->getDirection()==0) bDirect="FWD";
            if(bus->getDirection()==1) bDirect="BCK";
            cout << "B"<<bus->getBusID() << "[" << bDirect <<bus->getType() << "," << bus->getCapacity() << "] {";

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
}

template<typename T>
void Stations<T>::printFinishedPassengers(int stationNumber) {
   
        LinkedListp<Passenger>* finishList = list[stationNumber].getFinishList();
        Nodep<Passenger>* current = finishList->getHead();
        cout <<finishList->getCount()<<" Finished passengers: ";

        while (current != nullptr) {
            cout << current->getItem()->getID();
            if (current->getNext() != nullptr) {
                cout << ", ";
            }
            current = current->getNext();
        }
    
    cout << endl;
}

template<typename T>
void Stations<T>::printBusCounts(){
    int totalBuses = 0;
    int totalWBus = 0;
    int totalNBus = 0;

    for (int i = 1; i < size; ++i) {
        totalWBus += list[i].getWgarage()->getQuqeCount();
        totalNBus += list[i].getNgarage()->getQuqeCount();
    }

    totalBuses = totalWBus + totalNBus;

    cout << "buses: " << totalBuses << " [WBus: " << totalWBus << ", MBus: " << totalNBus << "]" << endl;
}

template<typename T>
void Stations<T>::printPassengerCounts(){
    int totalPassengers = 0;
    int numNormalPassengers = 0;
    int numSpecialPassengers = 0;
    int numWheelPassengers = 0;

    for (int i = 1; i < size; i++) {
        numNormalPassengers += list[i].getNP()->getQuqeCount();
        numNormalPassengers += list[i].getBNP()->getQuqeCount();

        numSpecialPassengers += list[i].getSP()->getSize();
        numSpecialPassengers += list[i].getBSP()->getSize();

        numWheelPassengers += list[i].getWP()->getQuqeCount();
        numWheelPassengers += list[i].getBWP()->getQuqeCount();
    }

    totalPassengers = numNormalPassengers + numSpecialPassengers + numWheelPassengers;

    cout << "passengers: " << totalPassengers << " [ NP: " << numNormalPassengers
         << ", SP: " << numSpecialPassengers << ", WP: " << numWheelPassengers << "]" << endl;
}