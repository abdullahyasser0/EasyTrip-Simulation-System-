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
            cout << "[ " << current->data->getID() << " ]";
            cout << "--->";

            current = current->next;
        }
        cout << "*\n";
    }
    void printBusQueue() const {
        NormalNode<T>* current = front;
        while (current != nullptr) {
            cout << "[ " << current->data->getNextStation() << " ]";
            cout << "--->";

            current = current->next;
        }
        cout << "*\n";
    }
    int count(){
        return Qsize;
    }
};
