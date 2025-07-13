#include<iostream>
using namespace std;
int lcm(int x,int y){
	if(x<=0&&y<=0) return 0;
	int i=2,sum=1;
	while(x>1||y>1){
		while(x%i==0||y%i==0){
			if(x%i==0) x=x/i;
			if(y%i==0) y=y/i;
			sum=sum*i;
		}
		i++;
	}
	return sum;
}
int main(){
	int x,y;
	cout<<"Enter First Number : ";
	cin>>x;
	cout<<"Enter Second Number : ";
	cin>>y;
	cout<<"\n\nLCM : "<<lcm(x,y)<<"\n\n";
	return 0;
}
