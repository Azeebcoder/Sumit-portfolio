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
		
		void insert(int val){
			node* new_node=new node(val);
			if(head==NULL){
				head=new_node;
				return;
			}
			node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new_node;
			return;
		}
		
		void display(){
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};

int getreversednumber(node* head){
	int number=0,k=1;
	node* temp=head;
	while(temp!=NULL){
		number=number+k*temp->data;
		temp=temp->next;
		k=k*10;
	}
	return number;
}

node* addnumber(node* head1,node* head2){
	node* new_node=new node(0);
	node* temp=new_node;
	int num1=getreversednumber(head1),num2=getreversednumber(head2);
	int sum=num1+num2;
	while(sum>0){
		node* nnode=new node(sum%10);
		temp->next=nnode;
		temp=temp->next;
		sum=sum/10;
	}
	return new_node->next;
}

int main(){
	linkedlist l,l1;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	
	l1.insert(6);
	l1.insert(7);
	l1.insert(8);
	l1.insert(9);
	l.display();
	l1.display();
	
	l.head=addnumber(l.head,l1.head);
	l.display();
	return 0;
}
