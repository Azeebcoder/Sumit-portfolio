#include"bits/stdc++.h"
using namespace std;
long long int decimaltobinary(long long int num){
	long long int s=1,sum=0;
	while(num>0){
		int rem=num%2;
		sum=sum+s*rem;
		s=s*10;
		num=num/2;
	}
	return sum;
}
long long int binarytodecimal(long long int num){
	long long int sum=0,i=0;
	while(num>0){
		int rem=num%10;
		sum=sum+(pow(2,i)*rem);
		num=num/10;
		i++;
	}
	return sum;
}
long long int decimaltooctal(long long int num){
	long long int s=1,sum=0;
	while(num>0){
		int rem=num%8;
		sum=sum+s*rem;
		s=s*10;
		num=num/8;
	}
	return sum;
}
long long int octaltodecimal(long long int num){
	long long int sum=0,i=0;
	while(num>0){
		int rem=num%10;
		sum=sum+(pow(8,i)*rem);
		num=num/10;
		i++;
	}
	return sum;
}
string decimaltohexadecimal(long long int num){
	string sum=" ";
	char s;
	while(num>0){
		int rem=num%16;
		if(rem<10) s=48+rem;
		else s=55+rem;
		sum=s+sum;
		num=num/16;
	}
	return sum;
}
long long int hexadecimaltodecimal(string num){
	long long int sum=0,i=0,power=num.length();
	while(i<num.length()){
		int rem;
		if(num[i]>='0'&&num[i]<='9'){
			rem=num[i]-48;
		}
		else if(num[i]>='a'&&num[i]<='f'){
			rem=num[i]-87;
		}
		else if(num[i]>='A'&&num[i]<='F'){
			rem=num[i]-55;
		}
		sum = sum+(pow(16,power-1)*rem);
		power--;
		i++;
	}
	return sum;
}
int main(){
	int n;
	cout<<"\n\n\t\tPress \n\n\n";
	cout<<"1  => Conversion from Decimal \n";
	cout<<"2  => Conversion from Binary \n";
	cout<<"3  => Conversion from Octal \n";
	cout<<"4  => Conversion from Hexadecimal \n\nEnter : ";
	cin>>n;
	long long int number;
	string number1;
	if(n==4){
		cout<<"\n\nEnter Number : ";
		cin>>number1;
	}
	else{
		cout<<"\n\nEnter Number : ";
		cin>>number;
	}
	if(n==1){
		cout<<"\n\nBinary Number : "<<decimaltobinary(number);
		cout<<"\n\nOctal Number : "<<decimaltooctal(number);
		cout<<"\n\nHexadecimal Number : "<<decimaltohexadecimal(number);
	}
	else if(n==2){
		int decimalnum=binarytodecimal(number);
		cout<<"\n\nDecimal Number : "<<decimalnum;
		cout<<"\n\nOctal Number : "<<decimaltooctal(decimalnum);
		cout<<"\n\nHexadecimal Number : "<<decimaltohexadecimal(decimalnum);
	}
	else if(n==3){
		int decimalnum=octaltodecimal(number);
		cout<<"\n\nBinary Number : "<<decimaltobinary(decimalnum);
		cout<<"\n\nDecimal Number : "<<decimalnum;
		cout<<"\n\nHexadecimal Number : "<<decimaltohexadecimal(decimalnum);
	}
	else if(n==4){
		int decimalnum=hexadecimaltodecimal(number1);
		cout<<"\n\nBinary Number : "<<decimaltobinary(decimalnum);
		cout<<"\n\nOctal Number : "<<decimaltooctal(decimalnum);
		cout<<"\n\nDecimal Number : "<<decimalnum;
	}
	else{
		cout<<"\n\nPagal h kya 'BKL'";
	}
	return 0;
}
