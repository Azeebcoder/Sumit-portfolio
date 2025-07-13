#include"bits/stdc++.h"
using namespace std;
int main(){
	int n,m;
	cout<<"Enter Row & Column : ";
	cin>>n>>m;
	int matrix[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
		}
	}
	int sr=0,er=n-1,sc=0,ec=m-1,elements=0;
	cout<<endl<<"Spiral = ";
	while(sr<=er||sc<=ec){
		for(int i=sc;i<=ec;i++){
			cout<<matrix[sr][i]<<" ";
			elements++;
		}
		if(elements>=m*n) break;
		sr++;
		for(int i=sr;i<=er;i++){
			cout<<matrix[i][ec]<<" ";
			elements++;
		}
		if(elements>=m*n) break;
		ec--;
		for(int i=ec;i>=sc;i--){
			cout<<matrix[er][i]<<" ";
			elements++;
		}
		if(elements>=m*n) break;
		er--;
		for(int i=er;i>=sr;i--){
			cout<<matrix[i][sc]<<" ";
			elements++;
		}
		sc++;
	}
	return 0;
}
