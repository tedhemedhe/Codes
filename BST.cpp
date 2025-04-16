// 50 20 70 10 30 90 110 -1 
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
this->data=d;
this->left=NULL;
this->right=NULL;
}
};

Node* insertToBST(Node* root, int d)
{
//base 
if(root==NULL)
{
root=new Node(d);
return root;
}
if(d>root->data)  //insert right
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
cin>>data;

while(data!=-1)
{
root= insertToBST(root, data);
cin>>data;
}
}

void levelorder(Node* root)
{
queue <Node*> q;
q.push(root);
q.push(NULL); //separator

while(!q.empty())
{
Node* temp= q.front();
q.pop();

if(temp == NULL) //purana level is traversed
{
cout<<endl; // for new line
if(!q.empty())  //queue still has a childnode
{
q.push(NULL);   // toh ek aur separatr ki jaraurat padegi
}
}

else
{
cout<< temp->data<<" ";

if(temp->left)
{
q.push(temp->left);
}

if(temp->right)
{
q.push(temp->right);
}
}
}
}

bool searchBST(Node* root, int x)
{
if(root==NULL)
{
return false;
}
if(root->data==x)
return true;

if(root->data>x)
{ //left me search
return searchBST(root->left, x);
}
else //agar bada hai x toh right me search
{
return searchBST(root->right, x);
}
}

Node* minVal(Node* root)
{
Node* temp= root;

while(temp->left!=NULL)
{
temp= temp->left;
}
return temp; //left me lowest value min value hogi
}

Node* maxVal(Node* root)
{
Node* temp= root;

while(temp->right!=NULL)
{
temp=temp->right;
}
return temp; //right me lowest value max value hogi
}


Node* deleteBST(Node* root, int val)
{

//base
if(root==NULL)
return root;

if(root->data==val)  //if found then delete
{  

// 0 child
if(root->left==NULL && root->right==NULL)
{
delete root;
return NULL;
}
//1 child
//left child
if(root->left!=NULL && root->right==NULL)
{
Node* temp=root->left;
delete root;
return temp;
}
//right child
if(root->left==NULL && root->right!=NULL)
{
Node* temp=root->right;
delete root;
return temp;
}

//2 child- min value assign kar denge aur root ke right me firse deletion kar denge
if(root->left!=NULL && root->right!=NULL)
{
int mini= (minVal(root->right)->data);
root->data= mini;

root->right= deleteBST(root->right, mini);
return root;
}

}

else if(root->data > val) //if not found
{
//left 
root->left= deleteBST(root->left, val);
return root;
}

else
{
//right
root->right= deleteBST(root->right, val);
return root;

}
}


int main()
{
Node* root=NULL;
cout<<"Enter data"<<endl;
takeInput(root);

cout<<"Printing the BST"<<endl;
levelorder(root);

cout<<"Enter search element"<<endl;
int x;
cin>>x;
if(searchBST(root,x)== true)
{
cout<<"Element found"<<endl;
}
else
cout<<"Element not found"<<endl;

cout<<"Min element is "<<minVal(root)->data<<endl;
cout<<"Max element is "<<maxVal(root)->data<<endl;


root= deleteBST(root, 30);
cout<<"Printing the BST after deletion"<<endl;
levelorder(root);



return 0;
}