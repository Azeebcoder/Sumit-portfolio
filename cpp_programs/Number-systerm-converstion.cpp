#include"bits/stdc++.h"
using namespace std;
int decimaltobinary(int num);
int binarytodecimal(int num);
int decimaltooctal(int num);
int octaltodecimal(int num);
string decimaltohexadecimal(int num);
int hexadecimaltodecimal(string num);
int main(){
	int n;
	cout<<"\n\n\t\tPress \n\n\n";
	cout<<"0  => Decimal to Binary \n";
	cout<<"1  => Binary to Decimal \n";
	cout<<"2  => Decimal to Octal \n";
	cout<<"3  => Octal to Decimal \n";
	cout<<"4  => Binary to Octal \n";
	cout<<"5  => Octal to Binary \n";
	cout<<"6  => Decimal to Hexadecimal \n";
	cout<<"7  => Hexadecimal to Decimal \n";
	cout<<"8  => Binary to Hexadecimal \n";
	cout<<"9  => Octal to Hexadecimal \n";
	cout<<"10 => Hexadecimal to Binary \n";
	cout<<"11 => Hexadecimal to Octal \n\n\n";
	cin>>n;
	if(n==0){
		int decimalnum;
		cout<<"\n\nEnter Decimal Number : ";
		cin>>decimalnum;
		int binarynum=decimaltobinary(decimalnum);
		cout<<"\n\nBinary Number : "<<binarynum;
	}
	else if(n==1){
		int binarynum;
		cout<<"\n\nEnter Binary Number : ";
		cin>>binarynum;
		int decimalnum=binarytodecimal(binarynum);
		cout<<"\n\nDecimal Number : "<<decimalnum;
	}
	else if(n==2){
		int decimalnum;
		cout<<"\n\nEnter Decimal Number : ";
		cin>>decimalnum;
		int octalnum=decimaltooctal(decimalnum);
		cout<<"\n\nOctal Number : "<<octalnum;
	}
	else if(n==3){
		int octalnum;
		cout<<"\n\nEnter Octal Number : ";
		cin>>octalnum;
		int decimalnum=octaltodecimal(octalnum);
		cout<<"\n\nDecimal Number : "<<decimalnum;
	}
	else if(n==4){
		int binarynum;
		cout<<"\n\nEnter Binary Number : ";
		cin>>binarynum;
		int decimalnum=binarytodecimal(binarynum);
		int octalnum=decimaltooctal(decimalnum);
		cout<<"\n\nOctal Number : "<<octalnum;
	}
	else if(n==5){
		int octalnum;
		cout<<"\n\nEnter Octal Number : ";
		cin>>octalnum;
		int decimalnum=octaltodecimal(octalnum);
		int binarynum=decimaltobinary(decimalnum);
		cout<<"\n\nBinary Number : "<<binarynum;
	}
	else if(n==6){
		int decimalnum;
		cout<<"\n\nEnter Decimal Number : ";
		cin>>decimalnum;
		cout<<"\n\nHexadecimal Number : "<<decimaltohexadecimal(decimalnum);;
	}
	else if(n==7){
		string hexadecimalnum;
		cout<<"\n\nEnter Hexadecimal Number : ";
		cin>>hexadecimalnum;
		int decimalnum=hexadecimaltodecimal(hexadecimalnum);
		cout<<"\n\nDecimal Number : "<<decimalnum;		
	}
	else if(n==8){
		int binarynum;
		cout<<"\n\nEnter Binary Number : ";
		cin>>binarynum;
		int decimalnum=binarytodecimal(binarynum);
		cout<<"\n\nHexadecimal Number : "<<decimaltohexadecimal(decimalnum);
	}
	else if(n==9){
		int octalnum;
		cout<<"\n\nEnter Octal Number : ";
		cin>>octalnum;
		int decimalnum=octaltodecimal(octalnum);
		cout<<"\n\nHexadecimal Number : "<<decimaltohexadecimal(decimalnum);
	}
	else if(n==10){
		string hexadecimalnum;
		cout<<"\n\nEnter Hexadecimal Number : ";
		cin>>hexadecimalnum;
		int decimalnum=hexadecimaltodecimal(hexadecimalnum);
		int binarynum=decimaltobinary(decimalnum);
		cout<<"\n\nBinary Number : "<<binarynum;
	}
	else if(n==11){
		string hexadecimalnum;
		cout<<"\n\nEnter Hexadecimal Number : ";
		cin>>hexadecimalnum;
		int decimalnum=hexadecimaltodecimal(hexadecimalnum);
		int octalnum=decimaltooctal(decimalnum);
		cout<<"\n\nOctal Number : "<<octalnum;
	}
	else{
		cout<<"\n\nPagal h kya 'BKL'";
	}
	return 0;
}
int decimaltobinary(int num){
	int s=1;
	int sum=0;
	while(num>0){
		int rem=num%2;
		sum=sum+s*rem;
		s=s*10;
		num=num/2;
	}
	return sum;
}
int binarytodecimal(int num){
	int sum=0,i=0;
	while(num>0){
		int rem=num%10;
		sum=sum+(pow(2,i)*rem);
		num=num/10;
		i++;
	}
	return sum;
}
int decimaltooctal(int num){
	int s=1;
	int sum=0;
	while(num>0){
		int rem=num%8;
		sum=sum+s*rem;
		s=s*10;
		num=num/8;
	}
	return sum;
}
int octaltodecimal(int num){
	int sum=0,i=0;
	while(num>0){
		int rem=num%10;
		sum=sum+(pow(8,i)*rem);
		num=num/10;
		i++;
	}
	return sum;
}
string decimaltohexadecimal(int num){
	string sum=" ";
	char s;
	while(num>0){
		int rem=num%16;
		if(rem<10){
			s=48+rem;
		}
		else{
			s=55+rem;
		}
		sum=s+sum;
		num=num/16;
	}
	return sum;
}
int hexadecimaltodecimal(string num){
	int sum=0,i=0;
	int power=num.length();
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
