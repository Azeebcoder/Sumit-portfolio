#include<stdio.h>
int main()
{
	int i,j,k,n;
	printf("Enter the Row : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n;j>i;j--)
		{
			printf(" ");
		}
		int first =1;
		for(k=1;k<=i;k++)
		{
			printf("%d ",first);
			first=first*(i-k)/k;
		}
		printf("\n");
	}
	return 0;
}
