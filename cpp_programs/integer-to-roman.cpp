#include<iostream>
#include<string>
using namespace std;
string integertoroman(int n){
	int arr[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string a[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	string ans;
	int A=12;
	while(n>0){
		while(arr[A]>n){
			A--;
		}
		for(int i=1;i<=n/arr[A];i++){
			ans=ans+a[A];
		}
		n=n%arr[A];
	}
	return ans;
}

int main(){
	cout<<"Integer to Roman Converter\n\tBy Sumit \n\n";
	int n;
	cout<<"Enter Number : ";
	cin>>n;
	cout<<"Roman Number : "<<integertoroman(n)<<endl;
}
