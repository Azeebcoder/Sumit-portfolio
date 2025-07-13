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
	for(int i=0;i<n-1;i++){
		int min=array[i];
		int k=i;
		for(int j=i+1;j<n;j++){
			if(array[j]<min){
				min=array[j];
				k=j;
			}
		}
		int temp=array[k];
		array[k]=array[i];
		array[i]=temp;
	}
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	return 0;
}
