#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;
	int count;
public:

	LinkedList()
	{
		count = 0;
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}
	
	void PrintList()	const
	{
		cout<<"\nprinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem()->getid() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}

	void Insert(const T &data){

		if(Head == nullptr){
			InsertBeg(data);
			return;
		}
		else{
			Node<T> *p = Head;
			while(p->getNext()){
				p = p->getNext();
				}
			Node<T> *R = new Node<T>(data);
			p->setNext(R);
			count++;
			return;

		}
		
	}

	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
};
#endif 