#pragma once

#include<iostream>
using namespace std;

template <class T>
class NormalNode {
public:
    T* data;
    NormalNode* next;
    NormalNode(T* d) : data(d), next(nullptr) {}
};

template <class T>
class Queue {
private:
    NormalNode<T>* front;
    NormalNode<T>* back;
    int Qsize;
public:
    Queue() : front(nullptr), back(nullptr),Qsize(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    NormalNode<T>* getfront(){
        return front;
    }

    NormalNode<T>* getback(){
        return back;
    }
    int getQSize(){
        return Qsize;
    }
    bool enqueue(T* newData) {
        NormalNode<T>* newNode = new NormalNode<T>(newData);
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        Qsize++;
        return true;
    }

        T* peek() const {
        if (isEmpty()) {
            return nullptr;
        }
        return front->data;
    }

    T* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }

        NormalNode<T>* dequeuedNode = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }

        T* frontData = dequeuedNode->data;
        delete dequeuedNode;
        Qsize--;
        return frontData;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
    NormalNode<T>* returnHead(){
        return front;
    }

    void printQueue() const {
        NormalNode<T>* current = front;
        while (current != nullptr) {
            cout << current->data->getID()<<",";
            //cout << "--->";

            current = current->next;
        }
        //cout << "*\n";
    }
    // void printBusQueue() const {
    //     NormalNode<T>* current = front;
    //     while (current != nullptr) {
    //         cout  << current->data->getNextStation();
    //         int direction=current->data->getDirection();
    //         string dir;
    //         if (direction==0) dir="FWD"; 
    //         if (direction==1) dir="BCK"; 
    //         cout << "[" << current->data->getType()   << "," << current->data->getCapacity() << "] {";
    //         // PriorityQueue<Passenger> inBusPass = current->data->getInBusPass();
    //         // while (!inBusPass.isEmpty()) {
    //         //     Passenger* passengerPtr = inBusPass.dequeue();  
    //         //     Passenger passenger = *passengerPtr;
    //         //     cout << passenger.getID();
    //         //     if (!inBusPass.isEmpty()) {
    //         //         cout << ", ";
    //         //         }
    //         // }
    //         current = current->next;
    //     }
    //     cout << "*\n";
    // }
    int getQuqeCount(){
        return Qsize;
    }

    int getSize(){
        NormalNode<T>* current = front;
        int count=0;
        while(current!=nullptr){
            current=current->next;
            count++;
        }
        return count;

    }
};
