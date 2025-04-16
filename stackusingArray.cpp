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
 
 for(int i=0; i<size; i++){
 temp[i]=arr[i];
 }
 
 delete[] arr;
 arr=temp;
 n=size;
 }
 
 public:
 Stack(int size=4)
 {
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
 
 int main(){
 Stack s(5);
 s.push(8);
 s.pop();
 s.push(78);
 s.push(5);
 s.pop();
 s.pop();
 cout<<s.peek()<<endl;
 s.push(74);
 s.push(56);
 s.pop();
 s.push(87);
 s.pop();
 s.push(25);
 
s.pop();
 cout<<s.peek()<<endl;
 
 return 0;
 }