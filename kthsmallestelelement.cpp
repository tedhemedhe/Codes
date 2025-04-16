//find kth smallest element in a bst
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
int data;
Node* left;
Node* right;

Node(int d)
{
this->data= d;
this->left= nullptr;
this->right= nullptr;
}
};


Node* insertToBST(Node* root, int d)
{
//base 
if(root== nullptr)
{
root=new Node(d);
return root;
}
if(d > root->data)  //insert right
{
root->right= insertToBST(root->right,d);
}
else     //insert left
{
root->left= insertToBST(root->left,d);
}
return root;
}


void takeInput(Node* &root )
{
int data;
cin >>data;

while(data!=-1)
{
root= insertToBST(root, data);
cin>>data;
}
}



  
  int solve(Node* root, int &i, int k)
  {
      if (root==NULL)
      return -1;
  
      //L
      int left= solve(root->left, i, k);
      if(left != -1)
      return left;
  
      //N
      i++;
      if(i==k)
      return root->data;
  
      //R
      return solve(root->right, i, k);
  }
  

  int kthSmallest(Node* root, int k) {
    int i=0;
int ans= solve(root, i, k);
return ans;

    
}

int main()
{
  Node* root=NULL;
cout<<"Enter data"<<endl;
takeInput(root);


cout<<"Enter kth element:"<<endl;
int k;
cin>>k;
int result = kthSmallest(root, k);
cout << "Kth smallest element is: " << result << endl;

}