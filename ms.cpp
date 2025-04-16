#include<iostream>
using namespace std;


void merge(int *arr, int s, int e) 
{

int mid = (s+e)/2;

int l1 = mid - s + 1;
int l2 = e - mid;

int *first = new int[l1];
int *second = new int[l2];

//copy values
int mainIndex = s;
 for(int i=0; i<l1; i++) 
{
     first[i] = arr[mainIndex++];
 }

mainIndex = mid+1;

for(int i=0; i<l2; i++)
 {
second[i] = arr[mainIndex++];
}

//merge 2 sorted arrays     
 int i = 0;
 int j = 0;
 mainIndex = s;

 while(i<l1 && j<l2)
    
 {
 if(first[i]<second[j]) 
 {
 arr[mainIndex++] = first[i++];
 }
 else
 {
 arr[mainIndex++] = second[j++];
 }
 }   

 while(i<l1) 
 {
 arr[mainIndex++] = first[i++];
  }

 while(j < l2 ) 
 {
 arr[mainIndex++] = second[j++];
 }

delete []first;
delete []second;  // free memory
}


void mergesort(int *arr, int s, int e)
{
//base case
if(s>=e)
{
return ;
}

int mid = (s+e)/2;

mergesort(arr, s, mid);
mergesort(arr, mid+1, e);
merge(arr, s, e);
}


int main()
{
int arr[10]={8,2,4,7,9,12,1,8,8,34};
int n=10;

mergesort(arr,0,n-1);

for(int i=0; i<n; i++)
{
cout<<arr[i]<<" ";
}
return 0;
}