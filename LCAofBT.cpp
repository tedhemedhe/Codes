//find lowest common ancestor of a binary tree
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

node* lowestCommonAncestor(node* root, node* p, node* q) {
  //base case 1
   if (root==NULL)
   return NULL;
  //base case 2
   if(root->data== p->data|| root->data== q->data)
   return root;

  node* leftAns = lowestCommonAncestor(root->left, p, q);
  node* rightAns = lowestCommonAncestor(root->right, p, q);

  if(leftAns!= NULL && rightAns!=NULL )
  return root;

  else if(leftAns!= NULL && rightAns==NULL )
  return leftAns;
  
  else if(leftAns == NULL && rightAns!=NULL )
  return rightAns;

  else
  return NULL;



}
int main()
{
node* root= NULL;
root= buildtree(root);
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

cout<<"Enter 2 nodes p and q:"<<endl;
int p,q;
cin>>p>>q;

node* p1;
node* q1;

p1= new node(p);
q1= new node(q);

node* result = lowestCommonAncestor(root, p1,q1);
cout << "LCA is " << result->data << endl;

}

