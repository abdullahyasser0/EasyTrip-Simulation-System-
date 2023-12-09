
#ifndef _NODE
#define _NODE
template <typename T>
class NodePriority
{
private:
	T item; // A data item
	int priority;
	NodePriority<T>* next; // Pointer to next node
public:
	NodePriority();
	NodePriority(const T& r_Item, int PriorityValue);
	NodePriority(const T& r_Item, int PriorityValue, NodePriority<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(NodePriority<T>* nextNodePtr);
	void setPriority(int priorityValue);
	T getItem() const;
	int getPriority() const;
	NodePriority<T>* getNext() const;
}; // end Node
#endif

template < typename T>
NodePriority<T>::NodePriority()
{
	next = nullptr;
}

template < typename T>
NodePriority<T>::NodePriority(const T& r_Item, int PriorityValue)
{
	item = r_Item;
	priority = PriorityValue;
	next = nullptr;
}

template < typename T>
NodePriority<T>::NodePriority(const T& r_Item, int PriorityValue, NodePriority<T>* nextNodePtr)
{
	item = r_Item;
	priority = PriorityValue;
	next = nextNodePtr;
}
template < typename T>
void NodePriority<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template <typename T>
void NodePriority<T>::setPriority(int priorityValue)
{
	priority = priorityValue;
}

template < typename T>
void NodePriority<T>::setNext(NodePriority<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T NodePriority<T>::getItem() const
{
	return item;
}

template <typename T>
int NodePriority<T>::getPriority() const
{
	return priority;
}

template < typename T>
NodePriority<T>* NodePriority<T>::getNext() const
{
	return next;
}