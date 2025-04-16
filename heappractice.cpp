#include <iostream>
using namespace std;

class heap
{
  public:
  int arr[100];
  int size=0;


heap()
{
  arr[0]= -1;
  size= 0;
}


void insertHeap(int val)
{
  size=size+1;
  int index=size;
  arr[index]=val;


  while(index>1)
  {
   int parent=index/2;

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

void deleteHeap()
{
   if(size==0)
   {
    cout<<"nothing to delete";
    return;
   }

   //step1
   arr[1]=arr[size];

   //step2
   size--;

   //step3
   int i=1;
   int left=2*i;
   int right= 2*i+1;

   if(left<size && arr[i]<arr[left])
   {
    swap(arr[i], arr[left]);
    i=left;
   }
   else if(right<size && arr[i]<arr[right])
   {
    swap(arr[i], arr[right]);
    i=right;
   }
   else
   return;
}

};

void heapify(int arr[], int n, int i)
{

  int largest= i;
  int left= 2*i;
  int right= 2*i+1;

  if(left<n && arr[largest]<arr[left])
   {
    
    largest=left;
   }
 if(right<n && arr[largest]<arr[right])
   {
    
    largest=right;
   }

   if(largest != i)
   {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
   }

}

void heapsort(int arr[], int n)
{

  int temp=n;

while(temp>1)
{
  //step 1
swap(arr[1], arr[temp]);

//step2
temp--;

//step3;
heapify(arr, temp, 1);
}

 
}

int main()
{
  heap h;
  h.insertHeap(50);
h.insertHeap(55);
h.insertHeap(53);
h.insertHeap(52);
h.insertHeap(54);
h.print();

h.deleteHeap();
h.print();

int arr[6]={ -1, 54, 53, 55, 52, 50};
int n=5;

//build heap
for(int i=n/2; i>0; i--)
{
  heapify(arr,n, i);
}

heapsort(arr, n);
cout<<"Printing sorted array:"<<endl;
for(int i=1;i<=n;i++)
{
cout<<arr[i]<< " ";
}
cout<<endl;
return 0;

}