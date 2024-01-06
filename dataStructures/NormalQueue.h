#pragma once
#include "Queue.h" 

template <class T>
class NormalQueue : public Queue<T> {
public:
    NormalQueue() : Queue<T>() {}

    ~NormalQueue() {}

bool passengerLeave(int id) {
    NormalNode<T>* current = this->getfront();
    NormalNode<T>* previous = nullptr;

    while (current != nullptr) {
        if (current->data->getID() == id) {
            if (previous == nullptr) {
                this->dequeue();
            } else {
                previous->next = current->next;
                delete current;
            }
            cout << "Passenger with ID: " << id << " left the station"<< endl;
            return true; 
        }

        previous = current;
        current = current->next;
    }

    return false;
}
};
