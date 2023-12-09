#include "Stack.h"
#include "LinkedQueue.h"
#include "NoramlQueue.h"
#include <iostream>
using namespace std;

template <typename N>
class Nodestation{

public :
    Nodestation<N>* next;
    Nodestation<N>* back;
    LinkedQueue<N>* watingpass; //waiting passangers pirority queue, Another one for normal passangers
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

        watingpass = nullptr; 
        busstop = nullptr; 

        Snumber  = 0;

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

    //try to make a funtion to return current station 

};




