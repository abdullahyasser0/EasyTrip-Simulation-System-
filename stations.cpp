#include <iostream>
using namespace std;

template <typename T>
class Nodestation{

public :
    Nodestation<T>* next;
    Nodestation<T>* back;
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
        
    }


};


template <typename T>
class StationsLL{

public:
    Nodestation<T>* Fstation;
    StationsLL() : Fstation(nullptr){}
    bool nostation(){
        return (Fstation==nullptr);
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

};



int main (){

    StationsLL<int> S1;
    S1.addstation();
    S1.addstation();
    S1.addstation();
    S1.addstation();
    S1.display();
    
    return 0;
}