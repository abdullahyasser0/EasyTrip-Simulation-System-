template<typename T>
class Nodep
{
private:
    T* item;           // Pointer to data item
    Nodep<T>* next;     // Pointer to next node

public:
    Nodep() : item(nullptr), next(nullptr) {}

    Nodep(T* newItem) : item(newItem), next(nullptr) {}

    void setItem(T* newItem)
    {
        item = newItem;
    }

    void setNext(Nodep<T>* nextNodePtr)
    {
        next = nextNodePtr;
    }

    T* getItem() const
    {
        return item;
    }

    Nodep<T>* getNext() const
    {
        return next;
    }
};