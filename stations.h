#include "Stack.h"
#include "LinkedQueue.h"
#include "NoramlQueue.h"
#include "LinkedListp.h"
#include "Passenger.h"
#include <iostream>
using namespace std;

template <typename N>
class Nodestation{

public :
    Nodestation<N>* next;
    Nodestation<N>* back;
    Queue* busstop; //buss stop
    
    //busses mantain "bayoumi says is should be on station 0 "
    
    int Snumber;

    
    LinkedListp<Passenger> NP; // Node Passenger
    LinkedListp<Passenger> WP;
    /*
    must add a variable for the waitiing passangers of type <queue> 
    this is the link between me and the passengers class

    how the buses and me will operate ?
    the buses will maintain <queue> , garage in station 0 <stack>, stop into the bus stops <queue> 
    */

    Nodestation(){

        next = nullptr;
        back = nullptr; 

        busstop = nullptr; 

        Snumber  = 0;

    }

    void PrintAll(){
        cout<<endl<<"NP list: ";
        NP.PrintList();
        cout<<endl<<"WP list: ";
        WP.PrintList();

    }

};


template <typename T>
class StationsDLL{

public:
    Nodestation<T>* Fstation;
    Stacks<T>* garage; //the one containing all the busses in the begining and the end

    StationsDLL(){ 
        Fstation = nullptr;
        garage = nullptr;
    }

    bool nostation(){
        return (Fstation==nullptr);
    }

    void garagebus(T* bus){
        garage->push(bus);
    }

    void addstation(){
        Nodestation<T>* newstation= new Nodestation<T>;

        if(nostation()){

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
    void addStationsByNumber(int numberOfStations){
        for (int i=0 ;i<numberOfStations ; i++){
            addstation();
                    cout<<"the station was succesfully made."<<endl;

        }
    }

    Nodestation<T> *ReturnStationPointer(int stationnumber){
        Nodestation<T>* temp=Fstation;
        while (temp->next!=nullptr)
        {
            if(temp->Snumber!=stationnumber) temp=temp->next;
            else return temp;
        }
        return nullptr;

    }

    void display(){
        if(!nostation()){
        Nodestation<T>* temp=Fstation;
        while (temp!=nullptr)
        {
            cout<<temp->Snumber<<endl;
            temp=temp->next;
        }
        }
    }

    void PrintAllStations() {
        Nodestation<T>* temp = Fstation;
        while (temp != nullptr) {
            temp->PrintAll();
            temp = temp->next;
        }
    }

    void addPassenger(Passenger* passenger) {
        if (Fstation == nullptr) {
            cerr << "Error: No stations available to add passengers." << endl;
            return;
        }

        int startStation = passenger->getStartStation();
        Nodestation<T>* stationPtr = ReturnStationPointer(startStation);

        if (stationPtr == nullptr) {
            cerr << "Error: Invalid start station for passenger." << endl;
            return;
        }

        string passengerType = passenger->getType();

        if (passengerType == "NP") {
            stationPtr->NP.Insert(passenger);
            cout << "Passenger added to NP list at Station " << startStation << endl;
        } else if (passengerType == "WP") {
            stationPtr->WP.Insert(passenger);
            cout << "Passenger added to WP list at Station " << startStation << endl;
        } else {
            cerr << "Error: Invalid passenger type." << endl;
        }
    }

    //try to make a funtion to return current station 

};