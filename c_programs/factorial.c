#include<stdio.h>
int n=5;
int main(int n){
	int fact = n*main(n-1);
	if(n==5){
		printf("%d",fact);
		return 0;
	}
	return fact;
	if(n==1) return 1;
}
