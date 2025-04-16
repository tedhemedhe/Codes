//singly linked lists
#include <iostream>
#include <map>

using namespace std;
class Node
{
public:
int value;
Node* next;


Node(int value)
{
this->value= value;
this->next= NULL;
} //constructor
};


void insertHead(Node* &head, int v)
{
    Node* temp= new Node(v);
    temp-> next= head;
    head= temp;
    }
    
   void insertTail(Node* &tail, int v)
{
    Node* temp= new Node(v);
    tail-> next= temp;
    tail= temp;
    }
    
    
    void print(Node *&head)
    {
    Node *temp= head;
    while(temp!= NULL)
    {
    cout<< temp->value<< " ";
    temp=temp->next;
    }
    cout<<endl;
    }
   
    int main()
    {
    Node* n1= new Node(11);
    
    Node* head=n1;
    Node* tail= n1;
    cout<<"Original:";
    print(head);
    
    insertHead(head,18);
    cout<<"after insert at head:";
    print(head);
    
    insertTail(tail,14);
     insertTail(tail,15);
    cout<<"after insert at tail:";
    print(head);
    
    return 0;
    }