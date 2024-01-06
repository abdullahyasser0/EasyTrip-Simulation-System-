#pragma once
#include "Nodep.h"
#include <iostream>
#include "../Passenger.h"
using namespace std;

template <typename T>
class LinkedListp
{
private:
    Nodep<T>* Head;
    int count;

public:
    LinkedListp() : Head(nullptr), count(0) {}



    Nodep<T>* getHead() const
    {
        return Head;
    }

    void PrintList() const
    {
        Nodep<T>* p = Head;

        while (p)
        {
            cout << "[ " << p->getItem()->getNextStation()<< " : " <<p->getItem()->getType()<< " ]";
            
            cout << "--->";
            p = p->getNext();
        }
        cout << "*\n";
    }
    void setHead(Nodep<T>* H){
        Head=H;
    }
    
    Nodep<T> *returnHead(){
        return Head;
    }
    // void deletenode(Nodep<T>* nedded){
    //     Nodep<T>* p = Head;
    //     if(p==nedded){Head=nullptr; delete p; return; }
    //     while(p->getNext()!=nedded){
    //         p=p->getNext();
    //     }
    //     p->setNext(p->getNext()->getNext());
    // }
    void deletenode(Nodep<T>* nedded){
    if (Head == nullptr || nedded == nullptr) {
        return;
    }
    if (Head == nedded) {
        Nodep<T>* temp = Head;
        Head = Head->getNext(); 
        delete temp; 
        return;
    }
    Nodep<T>* p = Head;
    while (p != nullptr && p->getNext() != nedded){
        p = p->getNext();
    }
    if (p != nullptr && p->getNext() == nedded) {
        Nodep<T>* temp = p->getNext(); 
        p->setNext(p->getNext()->getNext()); 
        delete temp; 
    } else {  
    }
}


    void DeleteFirst()
	{
        Nodep<T> *temp = Head;
		Head = Head->getNext();
        count--;
		delete temp;
	}

    int getCount(){
        return count;
    }
    void InsertBeg(T* data)
    {
        Nodep<T>* R = new Nodep<T>(data);
        R->setNext(Head);
        Head = R;
    }
    bool isEmpty(){
        return Head==nullptr;
    }
    
    void Insert(T* data)
    {
        if (Head == nullptr)
        {
            InsertBeg(data);
            return;
        }
        else
        {
            Nodep<T>* p = Head;
            while (p->getNext())
            {
                p = p->getNext();
            }
            Nodep<T>* R = new Nodep<T>(data);
            p->setNext(R);
            count++;
            return;
        }
    }

    void DeleteAll()
    {
        Nodep<T>* P = Head;
        while (Head)
        {
            P = Head->getNext();
            delete Head;
            Head = P;
        }
        count = 0;
    }

    

    void RemovePassenger(Passenger* passenger)
    {
        Nodep<T>* current = Head;
        Nodep<T>* previous = nullptr;
        while (current != nullptr)
        {
            if (current->getItem()->getID() == passenger->getID())
            {
                if (previous == nullptr)
                {
                    Head = current->getNext();
                }
                else
                {
                    previous->setNext(current->getNext());
                }

                delete current;
                return;
            }
        }
    }


};