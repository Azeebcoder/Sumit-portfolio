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
	for(int i=1;i<n;i++)
	{
		int j=i;
		while(array[j-1]>array[j]&&j>0){
			int temp=array[j];
			array[j]=array[j-1];
			array[j-1]=temp;
			j--;
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	return 0;
}
