#include<iostream>

using namespace std;

class QueueNode{
    public:
    QueueNode* next;
    int data;
    QueueNode(){data=0; next=NULL;}

};

class Queue{
    public:
    QueueNode* front;
    QueueNode* rear;
    Queue(){
        front=rear=NULL;
    }
    
    bool isEmpty() {
    return (front == NULL);
}


    void EnQueue(int x){
        QueueNode* newnode=new QueueNode();
        newnode->data=x;
        if(isEmpty()){
            front=rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }

    void displayQ(){
        QueueNode* temp=front;
        while (temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }

    void deQueue(){
        QueueNode* del=front;
        front=front->next;
        delete del;
    }

    int ViewFront(){
        return front->data;
    }
    
    int ViewRear(){
        return rear->data;
    }
};

