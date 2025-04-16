#include <bits/stdc++.h>
using namespace std;

class node
{
public:
int data;
node* left;
node* right;

node (int d)
{
this->data=d;
this->left= NULL;
this->right= NULL;
}
};

node* buildtree(node* root)
{
cout<<"Enter data:"<<endl;
int data;
cin>>data;

root= new node(data);
if(data== -1)
{
return NULL;
}

cout<<"Enter for left"<<endl;
root->left= buildtree(root->left);

cout<<"Enter for right"<<endl;
root->right= buildtree(root->right);

return root;
}
void levelorder(node* root)
{
queue <node*> q;
q.push(root);
q.push(NULL); //separator, ass lvl0 ke bad to new line jana hi hai

while(!q.empty())
{
node* temp= q.front();
q.pop();

if(temp == NULL) //purana level is traversed, so new line jana padega
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

if(temp->left) //if queue ka left is non-null , push in left
{
q.push(temp->left);
}

if(temp->right) //if queue ka right is non-null, push in right
{
q.push(temp->right);
}
}
}
}
void inorder(node* root)
{
//base
if(root==NULL)
return;

inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

void preorder(node* root)
{
//base
if(root==NULL)
return;

cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}

void postorder(node* root)
{
//base
if(root==NULL)
return;

postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";
}

int main()
{
node* root= NULL;
root= buildtree(root);
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

cout<<"inorder traversal is:";
inorder(root);

cout<<endl;
cout<<"preorder traversal is:";
preorder(root);

cout<<endl;
cout<<"postorder traversal is:";
postorder(root);

cout<<endl;
cout<<"levelorder traversal is:"<<endl;
levelorder(root);

return 0;
}



