#include"bits/stdc++.h"
using namespace std;
int main(){
	int n;
	cout<<"Enter Array size : ";
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++){
		cout<<"Enter "<<1+i<<" Element : ";
		cin>>array[i];
	}
	for(int i=0;i<n;i++){
		int flag=0;
		for(int j=0;j<n-i-1;j++){
			if(array[j]>array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0) break;
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	return 0;
}
