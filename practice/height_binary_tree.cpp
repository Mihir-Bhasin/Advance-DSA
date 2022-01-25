#include <bits/stdc++.h>

using namespace std;

class Node{
  public:
  class Node *left;
  class Node *right;
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
   return (1 +max(height(root->right),height(root->left)));
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
	cout<<height(root);
}