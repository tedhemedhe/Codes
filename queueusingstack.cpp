//queue using stack

#include <iostream>


using namespace std;

 class Stack{
 private:
 int *arr;
 int n;
 int top;
 
 //resize
 void resize(int size){
 int *temp= new int[size];
 
 for(int i=0; i<top; i++){
 temp[i]=arr[i];
 }
 
 delete[] arr;
 arr=temp;
 n=size;
 }
 
 public:
 Stack(int size=4){
 n=size;
 arr= new int[size];
 top=-1;
 }
 
 
 ~Stack(){
 delete[] arr;
 }
 
 void push(int a){
 if(top==n-1)
 {
 resize(2*n);
 }
 top++;
 arr[top]=a;
 }
 
 void pop(){
 if(top>=0)
 {
 top--;
 }
 else
 cout<<"Stack underflow";
 
 }
 
 int peek(){
 if(top>=0)
 return arr[top];
 else
 {
 cout<<"Stack is empty";
 return -1;
 }
 }
 bool empty(){
 if(top==-1)
 return true;
 else
 return false;
 }
 };
 
struct Queue
{

 
Stack s, s2;

void enqueue(int a)
{

//move all from first stack to 2nd
while( !s.empty())
{
s2.push(s.peek());
s.pop();
}

s.push(a);

//push all back to first
while(!s2.empty())
{
s.push(s2.peek());
s2.pop();
}
}

int dequeue()
{
if(s.empty())
{
return -1;
}

int a= s.peek();
s.pop();
return a;
}
};
 
 int main()
 {
Queue q;
 
 q.enqueue(2);
 q.enqueue(3);
 q.enqueue(4);
 
 cout<<q.dequeue()<<endl;
 cout<<q.dequeue()<<endl;
 cout<<q.dequeue()<<endl;
 
 return 0;
 }