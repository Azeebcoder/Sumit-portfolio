#include"bits/stdc++.h"
using namespace std;
long double decimaltobinary(double num);
int main(){
	long double decimalnum;
	cout<<"Enter Number : ";
	cin>>decimalnum;
	long double binarynum=decimaltobinary(decimalnum);
	cout<<"Binary Number : "<<binarynum;
	return 0;
}
long double decimaltobinary(double num){
	int binapointwala=num;
	long double pointwala=num-binapointwala;
	int sum1=0,k1=1;
	while(binapointwala>0){
		int rem=binapointwala%2;
		sum1=sum1+rem*k1;
		binapointwala=binapointwala/2;
		k1=k1*10;
	}
	long double sum2=0,k2=0.1;
	for(int i=0;i<5;i++){
		pointwala=pointwala*2;
		if(pointwala>=1){
			sum2=sum2+1*k2;
			pointwala=pointwala-1;
		}
		k2=k2*0.1;
	}
	long double sum=sum1+sum2;
	return sum;
}
