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
	
	int length(){
		node* temp=head;
		int count=1;
		while(temp->next!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}

	void findtargetsum(int sum){
		int start=1,end=length();
		node* temp1=head;
		node* temp2=tail;
		while(temp1!=temp2&&temp1->next!=temp2){
			if(temp1->data+temp2->data==sum){
				cout<<start<<" "<<end<<endl;
				return;
			}
			else if(temp1->data+temp2->data>sum){
				temp2=temp2->pre;
				end--;
			}
			else{
				temp1=temp1->next;
				start++;
			}
			
		}
		cout<<"NO FOUND"<<endl;
		return;
	}
	
	void display(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
};

int main(){
	doubleylinkedlist l;
	l.insertattail(1);
	l.insertattail(2);
	l.insertattail(4);
	l.insertattail(4);
	l.insertattail(7);
	l.insertattail(9);
	l.insertattail(11);
	l.display();
	l.findtargetsum(8);
	return 0;
}
