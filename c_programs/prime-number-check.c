#include<stdio.h>
int main()
{
	int i,n,s=0;
	printf("Enter the Number : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			s++;
		}
	}
	if(s==2)
	{
		printf("\n\nThe Number is Prime");
	}
	else
	{
		printf("\n\nThe Number is Not prime");
	}
	return 0;
}
