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

bool palindrome(node* &head){
	node* slow=head;
	node* fast=head;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	node* current=slow->next;
	node* previous=slow;
	slow->next=NULL;
	while(current!=NULL){
		node* next=current->next;
		current->next=previous;
		previous=current;
		current=next;
	}
	
	node* temp=head;
	while(previous!=NULL){
		if(temp->data!=previous->data) return false;
		temp=temp->next;
		previous=previous->next;
	}
	return true;
}

int main(){
	linkedlist l;
	l.insertattail(1);
	l.insertattail(2);
	l.insertattail(3);
	l.insertattail(2);
	l.insertattail(1);
	l.display();
	cout<<"\n"<<palindrome(l.head);
	return 0;
}








