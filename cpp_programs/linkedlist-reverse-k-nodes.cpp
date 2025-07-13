#include"bits/stdc++.h"
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int val){
			data=val;
			next=NULL;
		}
};

class linkedlist{
	public:
	node* head;
	
	linkedlist(){
		head=NULL;
	}
	
	void insertattail(int val){
		node* newnode=new node(val);
		if(head==NULL){
			head=newnode;
			return;
		}
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
	
	void display(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};


node* reversenodes(node* head,int n){
	if(head->next==NULL) return head;
	node* curr=head;
	
	node* pre=NULL;
	int i=1;
	while(i<=n&&curr!=NULL){
		node* next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
		i++;
	}
	if(curr!=NULL) head->next=reversenodes(curr,n);
	return pre;
}
int main(){
	linkedlist l;
	l.insertattail(1);
	l.insertattail(2);
	l.insertattail(3);
	l.insertattail(4);
	l.insertattail(5);
	l.insertattail(6);
	l.display();
	l.head=reversenodes(l.head,4);
	cout<<endl;
	
	l.display();
	return 0;
}
