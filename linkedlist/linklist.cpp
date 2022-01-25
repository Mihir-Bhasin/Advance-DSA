#include <bits/stdc++.h>
using namespace std;
//node for linkedlist

//basic already done.
class Node{
  public:
  Node *next;
  int key;
  Node(int k)
  {
    key=k;
    next=NULL;

  }
};


//Insert in a given position in a linked list

Node *insertPostion(Node *head, int pos,int data)
{
 Node* temp = new Node(data);
 if(pos==1)
 {
   temp->next=head;
   return temp;
 }
 Node *curr=head;
 for(int i=1;i<pos-2&&curr !=NULL;i++)
 {
   curr=curr->next;
 }
 if(curr==NULL)
  return head;

  temp->next=curr->next;
  curr->next=temp;
  return head;
}

//sorted insert insert according to sorting

Node *sortedinsert(Node *head,int x){
  Node *temp=new Node(x);
  if(head==NULL)
    return temp;
  if(x<head->data){
    temp->next=head;
    return temp;
  }
  Node *curr=head;
  while(curr->next!=NULL && curr->next->data<x)
   curr=curr->next;

   temp->next=curr->next;
   curr->next=temp;
   return head;



}