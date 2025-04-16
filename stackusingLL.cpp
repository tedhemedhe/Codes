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

class mStack
{
Node* head;

public:
mStack()
{
this->head= NULL;
}

bool isempty()
{
if(head==NULL)
return true;
else
return false;
}

void push(int nd){
 Node* temp= new Node(nd);
 
 if(!temp)
 {
 cout<<"overflow";
 }
 temp->next=head;
 head=temp;
 }
 
 void pop()
 {
 if(this->isempty())
 cout<<"Underflow";
 else
 {
 Node* flag=head;
 head=head->next;
 delete flag;
 }
}

int peek()
{
if(!isempty())
return head->d;
else
{
cout<<"Stack empty"<<endl;
return -1;
}
}
};


int main()
{
mStack s;

s.push(8);
s.push(78);
s.push(5);
 
s.pop();
s.pop();
s.pop();


cout<<"top element is: " << s.peek()<<endl;
return 0;
 }