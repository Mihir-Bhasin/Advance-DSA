#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  Node *left,*right;
  int key;
  Node(int k)
  {
    key=k;
    right=left=NULL;

  }
};

int height(Node *root)
{
  if(root==NULL)
    return 0;
    else
    return max(1+height(root->left),height(root->right));
}

bool isBalanced(Node *root)
{
  if(root==NULL)
  return true;
  int lh=height(root->left);
  int lr = height(root->right);
   return (abs(lh-lr)<=1 && isBalanced(root->left) && isBalanced(root->right));

}










int main() {
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	
	cout<<isBalanced(root);
}