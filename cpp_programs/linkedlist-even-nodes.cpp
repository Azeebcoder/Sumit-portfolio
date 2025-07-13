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

void evennodes(node* &head){
	node* even=head->next;
	node* temp=even;
	node* odd=head;
	while(odd->next!=NULL&&odd->next->next!=NULL){
		odd->next=odd->next->next;
		even->next=even->next->next;
		even=even->next;
		odd=odd->next;
	}
	
	odd->next=temp;
	
}

int main(){
	linkedlist l;
	l.insertattail(1);
	l.insertattail(2);
	l.insertattail(3);
	l.insertattail(4);
	l.insertattail(5);
	evennodes(l.head);
	l.display();
	return 0;
}
