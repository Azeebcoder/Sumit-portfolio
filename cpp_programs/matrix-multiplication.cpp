#include"bits/stdc++.h"
using namespace std;
int main(){
	int mr1,mr2,mc1,mc2;
	cout<<"Enter First Matrix row no. : ";
	cin>>mr1;
	cout<<"Enter First Matrix column no. : ";
	cin>>mc1;
	cout<<"Enter Second Matrix row no. : ";
	cin>>mr2;
	cout<<"Enter Second Matrix column no. : ";
	cin>>mc2;
	cout<<"\n\n";
	int matrix1[mr1][mc1],matrix2[mr2][mc2],result[mr1][mc2];
	if(mc1!=mr2){
		cout<<"Multiplication Not Possible";
		return 0;
	}
	cout<<"Enter First Matrix Elements : \n";
	for(int i=0;i<mr1;i++){
		for(int j=0;j<mc1;j++){
			cin>>matrix1[i][j];
		}
	}
	cout<<"Enter Second Matrix Elements : \n";
	for(int i=0;i<mr2;i++){
		for(int j=0;j<mc2;j++){
			cin>>matrix2[i][j];
		}
	}
	int sum;
	for(int i=0;i<mr1;i++){
		for(int j=0;j<mc2;j++){
			sum=0;
			for(int k=0;k<mc1;k++){
				sum=sum+matrix1[i][k]*matrix2[k][j];
			}
			result[i][j]=sum;
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
