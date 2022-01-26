#include <bits/stdc++.h>
using namespace std;
//node for linkedlist

//basic already done.
class Node{
  public:
  Node *next;
  int data;
  Node(int k)
  {
    data=k;
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
  // to avoid the changes in the later part of the linked list
   temp->next=curr->next;
   curr->next=temp;
   return head;
}

// Middle of linked list


void printmiddle(Node *head){

  if(head==NULL)
  return;
  Node *slow=head,*fast=head;
  while(fast!=NULL &&fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;

  }
  cout<<slow->data;
}
// nth node from end of linked list
// uisng 2 loops.

void printNthFromEnd(Node * head,int n){
    if(head==NULL)return;
    Node *first=head;
    for(int i=0;i<n;i++){
        if(first==NULL)return;
        first=first->next;
    }
    Node *second=head;
    while(first!=NULL){
        second=second->next;
        first=first->next;
    }
    cout<<(second->data);
}

//using 2 pointer with one iteration.
// nth node from end of linked list
void printNthFromEnd(Node *head,int n){
  if(head==NULL)
   return;
  Node *first =head;
  for(int i=0;i<n;i++)
  { if(first==NULL)
    first=first->next;
  }
  Node *second=head;
  while(first!=NULL)
{
  first=first->next;
  second=second->next;
}
cout<<second->data;
}


//Reverse a linked list.


Node *reverse(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
//reverse a linked list recussion.

Node *recRevL(Node *curr,Node *prev){
    if(curr==NULL)return prev;
    Node *next=curr->next;
    curr->next=prev;
    return recRevL(next,curr);
}


//reverse ll recursive kth node

Node *reverseK(Node *head,int k){
    Node *curr=head,*next=NULL,*prev=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        Node *rest_head=reverseK(next,k);
        head->next=rest_head;
    }
    return prev;
}