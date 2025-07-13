#include<stdio.h>
#include<stdlib.h>
int guess(int x);
int main()
{
	int n,s;
	printf("Enter 5 digit number : ");
	scanf("%d",&n);
	system("cls");
	s=200000+n-2;
	printf("\n\n\t\tWrite this number On Paper : %d\n\n\n\n\n",s);
	printf("\t\tEnter 5 digit number : %d\n",n);
	printf("\t\tEnter 5 digit number : ");
	scanf("%d",&n);
	printf("\t\tComputer's number    : %d\n",guess(n));
	printf("\t\tEnter 5 digit number : ");
	scanf("%d",&n);
	printf("\t\tComputer's number    : %d\n",guess(n));
	printf("\t\t                       _____\n");
	printf("\t\t                     + _____");
	printf("\n\n\n\n\t\t\tAdd These Numbers to see magic\n\n\n");
}
int guess(int x)
{
	int r,num=0,k=1;
	while(x>0)
	{
		r=x%10;
		r=9-r;
		num=k*r+num;
		x=x/10;
		k=k*10;
	}
	return num;
}