using namespace std;
#include <iostream>

template<typename T>

class Stacks{
    private:
    T* items;
    int top;
    const int size;
    
    public:
    Stacks(int Maxsize): size(Maxsize)
    {
        items = new T[size];
        top = -1; //new empty stack have its top =-1 as its the index of the top elemnt 
    }
    bool isempty() const
    {
        return top==-1;
    }

    bool push(T newItem){
        if (top==size-1) return false ; // top is index such that if the size is 3 we can have indeces od 0,1,2 so if top =2 ,size-1:(3-1) the stack is full.  

        top++;
        items[top]=newItem;
        return true;
    }

    bool pop(T TopEntry){
        if(isempty()) return false;

        TopEntry = items[top];  
        top--;
        return true;
    }

    bool peak(T TopEntry){
        if(isempty()) return false;

        TopEntry = items[top];
        return true;
    }
};