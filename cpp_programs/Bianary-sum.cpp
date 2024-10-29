#include"bits/stdc++.h"
using namespace std;
//Program to sum two binary numbers 
//  by Sumit
int main(){
	int a,b,hasil=0,ans=0,k=1;
	cout<<"Enter First Number : ";
	cin>>a;
	cout<<"Enter Second Number : ";
	cin>>b;
	while(a>0&&b>0){
		if(a%10==1&&b%10==1){
			if(hasil==0){
				ans = ans + 0*k;
				hasil=1;
			}
			else{
				ans = ans + 1*k;
				hasil = 1;
			}
		}
		else if(a%10==0&&b%10==0){
			if(hasil==1){
				ans = ans + 1*k;
				hasil = 0;
			}
			else{
				ans = ans + 0*k;
			}
		}
		else{
			if(hasil==1){
				ans = ans + 0*k;
				hasil = 1;
			}
			else{
				ans = ans + 1*k;
			}
		}
		k=k*10;
		a=a/10;
		b=b/10;
		while(a>0&&b<=0){
			if(a%10==1){
				if(hasil==1){
					ans = 0*k + ans;
					hasil=1;
				}
				else{
					ans = 1*k + ans;
					hasil = 0;
				}
			}
			k = k*10;
			a = a/10;
		}
		while(b>0&&a<=0){
			if(b%10==1){
				if(hasil==1){
					ans = 0*k + ans;
					hasil=1;
				}
				else{
					ans = 1*k + ans;
					hasil = 0;
				}
			}
			k = k*10;
			b = b/10;
		}
	}
	if(hasil==1){
		ans=hasil*k + ans;
	}
	cout<<endl<<"The sum is = "<<ans<<endl;
	return 0;
}
