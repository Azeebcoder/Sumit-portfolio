#include<stdio.h>
int main()
{
	int i,j,k,n,l;
	printf("Enter the Row : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n;j>i;j--)
		{
			printf("  ");
		}
		for(k=1;k<=i;k++)
		{
			printf("%d ",k);
		}
		for(l=1;l<i;l++)
		{
			printf("%d ",i-l);
		}
		printf("\n");
	}
	return 0;
}
