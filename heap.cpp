#include<iostream>
using namespace std;

//insertion, deletion, heapify, build heap, heapsort

class heap
{
public:
int arr[100];
int size=0;

heap()   //constructor
{
arr[0]= -1;
size= 0;
}

void insert (int val)   //INSERTION
{
size= size+1;
int index= size;
arr[index]= val;

while(index>1)
{
int parent= index/2;

if(arr[parent]<arr[index])
{
swap(arr[parent], arr[index]);
index=parent;
}
else
return;
}
}

void print()
{
for(int i=1; i<=size; i++)
{
cout<<arr[i]<< " ";
}
cout<<endl;
}

void deleteheap()    //DELETION
{
if( size==0)
{
cout<<"nothing to delete"<<endl;
return;
}

//step1
arr[1]=arr[size];

//step2
size--;

//step3  --> compare with children so tht root reaches correct position
int i=1;
while(i<size)
{
int leftI= 2*i;
int rightI= 2*i+1;

if(leftI<size && arr[i]<arr[leftI])
{
swap(arr[i],arr[leftI]);
i=leftI;
}

else if (rightI<size && arr[i]<arr[rightI])
{
swap(arr[i],arr[rightI]);
i=rightI;
}

else
return;
}
}

};

void heapify(int arr[], int n, int i)    //HEAPIFY
{
int largest=i;
int left= 2*i;
int right= 2*i+1;

if(left<=n && arr[largest]<arr[left])
{
largest=left;
}

if(right<=n   && arr[largest]<arr[right])
{
largest=right;
}

if(largest!=i) //means it is updated, so swap
{
swap(arr[largest], arr[i]);
heapify(arr, n, largest); //check for further correct positions
}
}

void heapsort(int arr[], int n)  //HEAPSORT
{
int temp=n;

while(temp>1)
{
//step1: swap
swap(arr[temp], arr[1]);

//step2
temp--;

//step3
heapify(arr, temp,1);
}

}

int main()
{
heap h;

h.insert(50);
h.insert(55);
h.insert(53);
h.insert(52);
h.insert(54);

h.print();

h.deleteheap();
h.print();

int arr[6]={ -1, 54, 53, 55, 52, 50};
int n=5;


for(int i=n/2; i>0; i--)   //BUILD HEAP FUNCTION
{
heapify(arr, n, i);
}



cout<<"Printing array again:"<<endl; 
for(int i=1;i<=n;i++)
{
cout<<arr[i]<< " ";
}
cout<<endl;


//heap sort
heapsort(arr, n);
cout<<"Printing sorted array:"<<endl;
for(int i=1;i<=n;i++)
{
cout<<arr[i]<< " ";
}
cout<<endl;


return 0;
}