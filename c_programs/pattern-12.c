#include<stdio.h>

int main()
{
	int i,j,n;
	printf("Enter the Row : ");
	scanf("%d",&n);
	if(n<3)
	{
		n=3;
	}
	if(n%2==0)
	{
		n=n+1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==(n/2)+1||j==(n/2)+1)
			{
				printf(" *");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}
