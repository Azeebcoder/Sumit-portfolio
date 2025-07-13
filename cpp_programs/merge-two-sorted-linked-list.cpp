#include"bits\stdc++.h"
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
			node* temp=head;
			if(head==NULL){
				head=newnode;
			}
			else{
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=newnode;
			}
		}
		void display(){
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<"NULL";
		}
	
};

int main(){
	linkedlist ll1,ll2;
	ll1.insertattail(1);
	ll1.insertattail(2);
	ll1.insertattail(3);
	ll1.display();
	return 0;
}
