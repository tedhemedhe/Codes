//using arraylist

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
 
 int main(){
Queue q(5);
 q.enqueue(8);
 q.enqueue(43);
 q.enqueue(988);
 q.enqueue(2);
 q.enqueue(4);
 q.enqueue(27);
   
 q.dequeue();
 q.dequeue();
 

 cout<<q.pfront()<<endl;
 
 return 0;
 }