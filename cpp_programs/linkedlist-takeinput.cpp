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

void takeinput(linkedlist &l){
	int n;
	cout<<"Enter -0 for stop entering value"<<endl;
	while(1){
		cin>>n;
		system("cls");
		cout<<"Enter -0 for stop entering value"<<endl;
		if(n==-0) break;
		else l.insertattail(n);
	}
}

int main(){
	linkedlist l;
	takeinput(l);
	cout<<"\n\n";
	l.display();
	return 0;
}
