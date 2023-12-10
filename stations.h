#include "Stack.h"
#include "LinkedQueue.h"
#include "NoramlQueue.h"
#include "LinkedList.h"
#include "Passenger.h"
#include <iostream>
using namespace std;

template <typename N>
class Nodestation{

public :
    Nodestation<N>* next;
    Nodestation<N>* back;
    LinkedQueue<N>* SPQueue; //waiting passangers pirority queue, Another one for normal passangers
    LinkedList<N>* WP;
    LinkedList<N>* NP;
    Queue* busstop; //buss stop
    
    //busses mantain "bayoumi says is should be on station 0 "
    
    int Snumber;

    /*
    must add a variable for the waitiing passangers of type <queue> 
    this is the link between me and the passengers class

    how the buses and me will operate ?
    the buses will maintain <queue> , garage in station 0 <stack>, stop into the bus stops <queue> 
    */

    Nodestation(){

        next = nullptr;
        back = nullptr; 

        SPQueue = nullptr; 
        busstop = nullptr; 

        Snumber  = 0;

    }

    void PrintAll(){
        cout<<endl<<"WP list: ";
        WP->display();
        cout<<endl<<"NP List: ";
        NP->display();
        cout<<endl<<"SPQueue: ";
        SPQueue->printQueue();
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

    //add functions to add passangers to WP and Np ele homa ala el raseef el mafrod yakhdo arguments of type passanger
    void AddPassanger(Passenger* pass)
    {
        string type = pass->getType();
        int stationnumber = pass->getStartStation();
        
        if(type=="NP")
        {
            ReturnStationPointer(stationnumber)->NP->Insert(pass);
        }
        else if(type=="WP")
        {
            ReturnStationPointer(stationnumber)->WP->Insert(pass);
        }

    }

    void addSpecialPassanger(Passenger* pass){
        
        int stationnumber = pass->getStartStation();
        int priority=pass->getPriority();
        ReturnStationPointer(stationnumber)->SPQueue->enqueue(pass,priority);
        
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

    void check(){
        cout<<"the station was succesfully made.";
    }

    //try to make a funtion to return current station 

};