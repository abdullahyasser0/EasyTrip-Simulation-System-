#include<iostream>
using namespace std;

template <class T>
class NormalNode {
public:
    T* data;
    NormalNode* next;
    int Qsize;
    NormalNode(T* d) : data(d), next(nullptr), Qsize(0) {}
};

template <class T>
class Queue {
private:
    NormalNode<T>* front;
    NormalNode<T>* back;

public:
    Queue() : front(nullptr), back(nullptr) {}

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

    void printQueue() const {
        NormalNode<T>* current = front;
        while (current != nullptr) {
            cout << "[ " << current->data->getID() << " ]";
            cout << "--->";

            current = current->next;
        }
        cout << "*\n";
    }

    int count(){
        return Qsize;
    }
};
