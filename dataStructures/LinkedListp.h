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
            cout << "[ " << p->getItem()->getID() << " ]";
            
            cout << "--->";
            p = p->getNext();
        }
        cout << "*\n";
    }
    
    
    Nodep<T> *returnHead(){
        return Head;
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