//using linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
int d;
Node *next;

Node(int nd)
{
this->d=nd;
this->next= NULL;
}
};

class Queue
{
Node *qfront, *rear;

public:
Queue()
{
qfront= NULL;
rear= NULL;
}

bool isempty()
{
if(qfront == NULL)
return true;
else
return false;
}

void enqueue(int nd){
 Node* temp= new Node(nd);
 
 if(this->isempty()) //if queue empty, only front and rear
 {
 qfront=rear=temp;
 return;
 }
 rear->next= temp;
 rear=temp;  //adding newnode
 }
 void dequeue()
 {
 if(this->isempty())
 cout<<"Underflow";
 else
 {
 Node* flag= qfront;
qfront=qfront->next;

//if front is Null then rear also null
if(qfront==NULL)
rear= NULL;

 delete flag;
 }
}

int pfront()
{
if(!isempty())
return qfront->d;
else
{
cout<<"Stack empty";
return -1;
}
}
int prear()
{
if(!isempty())
return rear->d;
else
{
cout<<"Stack empty";
return -1;
}
}
};


int main()
{
Queue q;
 q.enqueue(8);
 q.enqueue(43);
 q.enqueue(988);
 q.enqueue(2);
  q.enqueue(4);
   q.enqueue(27);
   
 q.dequeue();
 q.dequeue();
 

 cout<<"Queue front is: "<<q.pfront()<<endl;
 cout<<"Queue rear is:" << q.prear()<<endl;
 return 0;
 }