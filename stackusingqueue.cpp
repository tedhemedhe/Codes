//stack using queue
#include <iostream>
#include <map>
using namespace std;

class Queue
{
private:
int *arr;
int qfront;
int rear;
int size;

//resize
 void resize(int size){
 this->size= size;
 int *temp= new int[size];
 
 for(int i=0; i<rear; i++){
 temp[i]=arr[i];
 }
 
 delete[] arr;
 arr=temp;

 }
 
 public:
 Queue(int size=100){
 this->size= size;
 arr= new int[size];
 qfront=0;
 rear=0;
 }
 
 void enqueue(int a)
 {
 if(rear==size)
 {
 resize(2*size);
 }
 else
 {
  arr[rear]=a;
 rear++;
 }
 }
 
void dequeue()
 {
 if(qfront==rear)
 {
 cout<<"underflow";
 return;
 }
 else
 {
 
 arr[qfront]=-1;
 qfront++;
 
 if(qfront==rear)
 {
 qfront=0;
 rear=0;
 }
return;
 }
 }
 
 int pfront()
 {
 if(qfront==rear)
 {
 return -1;
 }
 else
 return arr[qfront];
 }
 
 bool isEmpty()
 {
 if(qfront==rear)
 return true;
 else
 return false;
 }
 };
 
 struct Stack
{

 
Queue q, q2;

void push(int a)
{

//move all from first queue to 2nd
while( !q.isEmpty())
{
q2.enqueue(q.pfront());
q.dequeue();
}

q.enqueue(a);

//push all back to first
while(!q2.isEmpty())
{
q.enqueue(q2.pfront());
q2.dequeue();
}
}

int pop()
{
if(q.isEmpty())
{
return -1;
}

int a= q.pfront();
q.dequeue();
return a;
}
};

int main()
 {
Stack s;
 
 s.push(2);
s.push(3);
 s.push(4);
 
 cout<<s.pop()<<endl;
 cout<<s.pop()<<endl;
 cout<<s.pop()<<endl;
 
 return 0;
 }