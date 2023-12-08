
#ifndef _NODE
#define _NODE
template <typename T>
class Node
{
private:
	T item; // A data item
	int priority;
	Node<T>* next; // Pointer to next node
public:
	Node();
	Node(const T& r_Item, int PriorityValue);
	Node(const T& r_Item, int PriorityValue, Node<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(Node<T>* nextNodePtr);
	void setPriority(int priorityValue);
	T getItem() const;
	int getPriority() const;
	Node<T>* getNext() const;
}; // end Node
#endif

template < typename T>
Node<T>::Node()
{
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& r_Item, int PriorityValue)
{
	item = r_Item;
	priority = PriorityValue;
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& r_Item, int PriorityValue, Node<T>* nextNodePtr)
{
	item = r_Item;
	priority = PriorityValue;
	next = nextNodePtr;
}
template < typename T>
void Node<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template <typename T>
void Node<T>::setPriority(int priorityValue)
{
	priority = priorityValue;
}

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T Node<T>::getItem() const
{
	return item;
}

template <typename T>
int Node<T>::getPriority() const
{
	return priority;
}

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}