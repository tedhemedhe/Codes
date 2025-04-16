//QUICK SORT Gauri

#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
int pivot= arr[s];

int c=0;
for(int i=s+1; i<=e; i++)
{
if(arr[i]<=pivot)
{
c++;
}
} //count number of elements less thn pivot 

int pi=s+c; // shift pivot, to partition into 2 parts
swap(arr[pi],arr[s]);

int i=s; 
int  j=e;  //for sorting left and right parts\

while(i<pi and j>pi)
{
while(arr[i]<=pivot)  // elemt left me hi hai and pivot se chhota hai, toh np
{
i++;
}

while(arr[j]>=pivot) //elemt right me hi hai and pivot se bada hai toh np
{
j--;
}

if(i<pi && j>pi)
{
swap(arr[i++], arr[j--]);  //left me bada, right me chhota toh swap

}

}
return pi;
}


void quicksort(int arr[], int s, int e)
{
//base case
if(s>e)
return ;

//prtition
int p= partition(arr,s,e);

//recursion
quicksort(arr,s,p-1); //left part
quicksort(arr,p+1,e); //right part

}

int main()
{
int arr[10]={8,2,4,7,9,12,1,8,8,34};
int n=10;

quicksort(arr,0,n-1);

for(int i=0; i<n; i++)
{
cout<<arr[i]<<" ";
}
return 0;
}