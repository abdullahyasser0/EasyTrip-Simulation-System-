#include <iostream>
#include "Buses.h"
using namespace std;

class NodeStack {
public:
    Bus* data;
    NodeStack* next;

    NodeStack(Bus* newData){
        data=newData;
        next=nullptr;
    }
}; 

class Stack {
private:
    NodeStack* top;

public:
    Stack() : top(nullptr) {}

~Stack() {
    while (!isempty()) {
        NodeStack* temp = top;
        top = top->next;
        delete temp;
    }
}

    bool isempty() const {
        return top == nullptr;
    }

    void push(Bus* newItem) {
        NodeStack* newNode = new NodeStack(newItem);
        newNode->next = top;
        top = newNode;
    }

    bool pop(Bus*& TopEntry) {
        if (isempty()) {
            return false;
        }

        NodeStack* temp = top;
        TopEntry = temp->data;
        top = temp->next;
        delete temp;

        return true;
    }

    void printStack() const {
        NodeStack* current = top;
        while (current != nullptr) {
            cout << current->data->getType() << endl;
            current = current->next;
        }
    }

    int countBuses() const {
        int count = 0;
        NodeStack* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};