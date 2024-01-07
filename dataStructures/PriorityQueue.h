#pragma once
#include <iostream>
using namespace std;

template <typename T>
class PriorityNode {
private:
    T* item;
    PriorityNode* next;
    PriorityNode* prev;
    int priority;

public:
    T* getItem() const {
        return item;
    }

    PriorityNode* getNext() const {
        return next;
    }

    PriorityNode* getPrev() const {
        return prev;
    }

    int getPriority() const {
        return priority;
    }

    void setNext(PriorityNode* n) {
        next = n;
    }

    void setPrev(PriorityNode* p) {
        prev = p;
    }

    void setPriority(int prio) {
        priority = prio;
    }


    PriorityNode(T* p) : item(p), next(nullptr), prev(nullptr) {}
};

template <typename T>
class PriorityQueue {
private:
    PriorityNode<T>* front;
    PriorityNode<T>* back;
    int count = 0;
    //for function size
    int size;

public:
    PriorityQueue() : front(nullptr), back(nullptr) {}

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    PriorityNode<T>* getFront(){
        if(!isEmpty()){
        return front;
        }
        else return nullptr;
    }
    int getCount(){
        return count;
    }
    bool enqueue(T* newPassenger, int prio) {
        newPassenger->setPriority(prio);
        PriorityNode<T>* newNode = new PriorityNode<T>(newPassenger);
        if (isEmpty() || newPassenger->getPriority() > front->getItem()->getPriority()) { 
            newNode->setNext(front);
            front = newNode;
        } else {
            PriorityNode<T>* prev = nullptr;
            PriorityNode<T>* current = front;

            while (current != nullptr && newPassenger->getPriority() <= current->getItem()->getPriority()) { 
                prev = current;
                current = current->getNext();
            }

            if (prev == nullptr) {
                newNode->setNext(front);
                front = newNode;
            } else {
                prev->setNext(newNode);
                newNode->setNext(current);
            }
        }

        return true;
    }

    T* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }

        PriorityNode<T>* dequeuedNode = front;
        front = front->getNext();
        if (front != nullptr) {
            front->setPrev(nullptr);
        } else {
            back = nullptr;
        }

        T* frontPassenger = dequeuedNode->getItem();
        //delete dequeuedNode;
        count--;
        return frontPassenger;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void printQueue() const {
        PriorityNode<T>* current = front;
        while (current != nullptr) {
            cout <<  current->getItem()->getID() << ",";

            current = current->getNext();
        }
    }

    void printSPQueue() const {
        PriorityNode<T>* current = front;
        while (current != nullptr) {
            cout <<  current->getItem()->getID()<<"("<<current->getItem()->getStrPriopity() <<")"<< ",";
            

            current = current->getNext();
        }
    }
  
    void enqueueInsideBus(T* newPassenger) {
        PriorityNode<T>* newNode = new PriorityNode<T>(newPassenger);
        if (isEmpty() || newPassenger->getEndStation() < front->getItem()->getEndStation()) { 
            newNode->setNext(front);
            front = newNode;
        } else {
            PriorityNode<T>* prev = nullptr;
            PriorityNode<T>* current = front;

            while (current != nullptr && newPassenger->getEndStation() >= current->getItem()->getEndStation()) { 
                prev = current;
                current = current->getNext();
            }

            if (prev == nullptr) {
                newNode->setNext(front);
                front = newNode;
            } else {
                prev->setNext(newNode);
                newNode->setNext(current);
            }
        }
        count++;
    }
    PriorityNode<T>* returnHead(){
        return front;
    }
    int getSize(){
        int count=0;
        PriorityNode<T> *temp=front;
        while (temp!=nullptr)
        {
            temp=temp->getNext();
            count++;
        }
        return count;
    }

    int getSize() const {
        return size;
    }
};