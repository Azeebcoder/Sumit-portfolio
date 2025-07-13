#include"bits\stdc++.h"
using namespace std;
int main(){
	int n,max=-1;
	cout<<"Enter Size : ";
	cin>>n;
	int arr[n];
	cout<<"Enter Elements : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(max<arr[i]) max=arr[i];
	}
	int check[max+1];
	for(int i=0;i<max;i++){
		check[i]=0;
	}
	for(int i=0;i<n;i++){
		check[arr[i]]++;
	}
	for(int i=1;i<max;i++){
		check[i]=check[i-1]+check[i];
	}
	int out[n];
	for(int i=n-1;i>=0;i--){
		out[--check[arr[i]]]=arr[i];
	}
	for(int i=0;i<n;i++){
		cout<<out[i]<<" ";
	}
	return 0;
}
