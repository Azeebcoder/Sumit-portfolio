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

int lenth(node* head){
	int l=0;
	while(head!=NULL){
		head=head->next;
		l++;
	}
	return l;
}

int findintersection(node* &head1,node* &head2){
	
	node* temp1=head1;
	node* temp2=head2;
	int count1=lenth(head1);
	int count2=lenth(head2);
	int step;
	if(count1<count2){
		temp1=head2;
		temp2=head1;
		step=count2-count1;
	}
	else if(count2<=count1){
		temp1=head1;
		temp2=head2;
		step=count1-count2;
	}
	for(int i=1;i<=step;i++){
		temp1=temp1->next;
	}
	while(temp1!=NULL&&temp2!=NULL){
		if(temp1==temp2){
			return 1;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return 0;
	
}

int main(){
	linkedlist l1,l2;
	l1.insertattail(1);
	l1.insertattail(2);
	l1.insertattail(3);
	l1.insertattail(4);
	l1.insertattail(5);
	l1.insertattail(6);
	
	l2.insertattail(1);
	l2.insertattail(2);
	l2.insertattail(3);
	l2.insertattail(4);
	
//	node* temp1=l1.head;
//	node* temp2=l2.head;
//	
//	while(temp2->next!=NULL){
//		temp2=temp2->next;
//	}
//	for(int i=1;i<=5;i++){
//		temp1=temp1->next;
//	}
//	temp2->next=temp1;
	cout<<findintersection(l1.head,l2.head);
	return 0;
}
