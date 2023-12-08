#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_
#include <iostream>
using namespace std;

#include "PriorityNode.h"
#include "QueueADT.h"

template <typename T>
class LinkedQueue :public QueueADT<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, int priority);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~LinkedQueue();
};


template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}


template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry, int priority)
{
	Node<T>* newNodePtr = new Node<T>(newEntry, priority);
	if (isEmpty()) {
		frontPtr = newNodePtr;
		backPtr = newNodePtr;
	}
	else {
		Node<T>* prevPtr = nullptr;
		Node<T>* currentPtr = frontPtr;
		while (currentPtr != nullptr && priority <= currentPtr->getPriority())
		{
			prevPtr = currentPtr;
			currentPtr = currentPtr->getNext();
		}
		if (prevPtr == nullptr)
		{
			newNodePtr->setNext(frontPtr);
			frontPtr = newNodePtr;
		}
		else
		{
			prevPtr->setNext(newNodePtr);
			newNodePtr->setNext(currentPtr);
			if (currentPtr == nullptr)
			{
				backPtr = newNodePtr;
			}
		}
	}

	return true;
}

template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;

	delete nodeToDeletePtr;

	return true;
}


template <typename T>
bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}


template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	cout << "\nStarting LinkedQueue destructor...";
	cout << "\nFreeing all nodes in the queue...";

	T temp;
	while (dequeue(temp));

	cout << "\n Is LinkedQueue Empty now?? ==> " << boolalpha << isEmpty();
	cout << "\nEnding LinkedQueue destructor..." << endl;
}

#endif