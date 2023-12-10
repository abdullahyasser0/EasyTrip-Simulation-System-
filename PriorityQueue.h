#include "Passenger.h"

class PriorityNode {
public:
    Passenger* passenger;
    PriorityNode* next;
    PriorityNode* prev;

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

    void enqueue(Passenger* passenger) {
        PriorityNode* newNode = new PriorityNode(passenger);

        if (isEmpty()) {
            front = back = newNode;
        } else {
            PriorityNode* current = front;
            while (current != nullptr && passenger->getPriority() <= current->passenger->getPriority()) {
                current = current->next;
            }

            if (current == front) {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            } else if (current == nullptr) {
                back->next = newNode;
                newNode->prev = back;
                back = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
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
