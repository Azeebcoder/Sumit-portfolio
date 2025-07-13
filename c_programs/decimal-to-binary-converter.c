#include<stdio.h>
int main()
{
	int n,r,num=0,s=1;
	printf("\n\nEnter decimal number : ");
	scanf("%d",&n);
	while(n>0)
	{
		r=n%2;
		num=(r*s)+num;
		n=n/2;
		s=s*10;
	}
	printf("\n\nBinary number is = %d\n\n",num);
	return 0;
}
