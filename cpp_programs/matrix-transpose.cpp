#include"bits/stdc++.h"
using namespace std;
int main(){
	int n;
	cout<<"Enter Row No. : ";
	cin>>n;
	int array[n][n];
	cout<<"Enter Matrix : \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>array[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int temp=array[i][j];
			array[i][j]=array[j][i];
			array[j][i]=temp;
		}
	}
	cout<<endl<<"Transpose matrix : "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<array[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
