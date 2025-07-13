#include"bits/stdc++.h"
using namespace std;
int main(){
	int n;
	cout<<"Enter Size : ";
	cin>>n;
	int array[n];
	cout<<"\n\n";
	for(int i=0;i<n;i++){
		cout<<"Enter "<<1+i<<" Element : ";
		cin>>array[i];
	}
	int k;
	cout<<"\n\nEnter Number You want to find : ";
	cin>>k;
	int sp=0,ep=n-1;
	while(sp<ep&&k!=array[sp]+array[ep]){
		if(array[sp]+array[ep]>k){
			ep--;
		}
		else{
			sp++;
		}
	}
	if(sp<ep){
		cout<<"\nIndexes = "<<sp+1<<" "<<ep+1;
	}
	else{
		cout<<"Can't Found";
	}
	return 0;
}
