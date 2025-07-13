#include"bits/stdc++.h"
using namespace std;
class node{
	public:
		int data;
		node* pre;
		node* next;
		
		node(int val){
			data=val;
			pre=NULL;
			next=NULL;
		}
};

class doubleylinkedlist{
	public:
	node* head;
	node* tail;
	
	doubleylinkedlist(){
		head=NULL;
		tail=NULL;
	}
	
	void insertathead(int val){
		node* new_node=new node(val);
		if(head==NULL){
			head=new_node;
			tail=new_node;
			return;
		}
		new_node->next=head;
		head->pre=new_node;
		head=new_node;
		return;
	}
	
	void insertattail(int val){
		node* new_node=new node(val);
		if(head==NULL){
			head=new_node;
			tail=new_node;
			return;
		}
		new_node->pre=tail;
		tail->next=new_node;
		tail=new_node;
		return;
		
	}
	
	void insertatpos(int val,int k){
		node* new_node=new node(val);
		node* temp=head;
		int count=1;
		while(count<k){
			if(temp==NULL){
				cout<<"ERROR";
			}
			temp=temp->next;
			count++;
		}
		if(temp==head){
			insertathead(val);
			return;
		}
		if(temp==tail){
			insertattail(val);
			return;
		}
		new_node->next=temp;
		new_node->pre=temp->pre;
		temp->pre->next=new_node;
		temp->pre=new_node;
		
		return;
	}
	
	void display(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};

void distancecritical(int arr[],node* head){
	node* temp=head->next;
	int pos=0,first,tem=0,second,last;
	while(temp->next!=NULL){
		pos++;
		if((temp->data>temp->pre->data&&temp->data>temp->next->data)||(temp->data<temp->pre->data&&temp->data<temp->next->data)){
			tem++;
			if(tem==1){
				first=pos;
			}
			else if(tem==2){
				second=pos;
			}
			else{
				last=pos;
			}
		}
		temp=temp->next;
	}
	arr[0]=second-first;
	arr[1]=last-first;
	return;
}

int main(){
	doubleylinkedlist l;
	l.insertattail(1);
	l.insertattail(3);
	l.insertattail(2);
	l.insertattail(5);
	l.insertattail(4);
	int arr[2];
	distancecritical(arr,l.head);
	cout<<arr[0]<<" "<<arr[1]<<endl;
	l.display();
	return 0;
}

