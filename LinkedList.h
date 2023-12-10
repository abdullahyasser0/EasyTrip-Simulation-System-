//==================================
//aboudi code

#include<iostream>
using namespace std;

template<typename T>
class Node
//this class is contaning the data and pointer to the  
{
    public:
    Node<T>* next;
    T data;
    
};

template<typename T>
class LinkedList
{
    public:

    Node<T>* head;
    LinkedList(){head =NULL;}

    bool isempty()
    {
       return (head==NULL);
    }


    void display()
        {
            Node<T> *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }

        }
    
    void Insert(T value){
        Node<T>* newnode=new Node<T>;
        newnode->data=value;
        Node<T>* temp=head;

        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;

    }

    void del(T value){
        Node<T>* delitem=new Node<T>;
        Node<T>* temp = head;

        while (temp->next->data!=value)
        {
            temp=temp->next;
        }
        delitem=temp->next;
        temp->next=delitem->next;
        delete delitem;
        

    }

    void delfirst(){
        Node<T>* delitem=head;
        head=head->next;
        delete delitem;
    }

    void merge(LinkedList<T>L){
        Node<T>* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=L.head;
    }
    T sumrec(Node<T>*newnode){
        T count=0;
        if(newnode->next==NULL)return (count+=newnode->data);
        else {
            count=newnode->data;
            newnode=newnode->next;
            return count+sumrec(newnode);
        }
        
    }


	void DeleteAll()
	{
		Node<T> *P = head;
		while (head)
		{
			P = head->next;
			delete head;
			head = P;
		}
	}
};
