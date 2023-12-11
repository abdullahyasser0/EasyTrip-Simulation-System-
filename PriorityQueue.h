#include "Passenger.h"

class PriorityNode {
public:
    Passenger* passenger;
    PriorityNode* next;
    PriorityNode* prev;

    Passenger* getitem(){
        return  passenger;
    }    
    PriorityNode(Passenger* p) : passenger(p), next(nullptr), prev(nullptr) {}
};


class PriorityQueue {
private:
    PriorityNode* front;
    PriorityNode* back;

public:
    PriorityQueue() : front(nullptr), back(nullptr) {}

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

bool enqueue(Passenger* newPassenger) {
    PriorityNode* newNode = new PriorityNode(newPassenger);
    if (isEmpty() || newPassenger->getPriority() > front->passenger->getPriority()) {
        newNode->next = front;
        front = newNode;
    } else {
        PriorityNode* prev = nullptr;
        PriorityNode* current = front;

        while (current != nullptr && newPassenger->getPriority() <= current->passenger->getPriority()) {
            prev = current;
            current = current->next;
        }

        if (prev == nullptr) {
            newNode->next = front;
            front = newNode;
        } else {
            prev->next = newNode;
            newNode->next = current;
        }
    }

    return true;
}

    Passenger* dequeue() {
        if (isEmpty()) {
            return nullptr; 
        }

        PriorityNode* dequeuedNode = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            back = nullptr;
        }

        Passenger* frontPassenger = dequeuedNode->passenger;
        delete dequeuedNode;

        return frontPassenger;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void printQueue() const {
        PriorityNode* current = front;
        while (current != nullptr) {
            cout << "[ " << current->passenger->getID() << " ]";
            cout << "--->";

            current = current->next;
        }
        cout << "*\n";
    }
};
