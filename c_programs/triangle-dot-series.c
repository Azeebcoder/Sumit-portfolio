#include<stdio.h>
int main()
{
	int i,n,s=0;
	printf("Enter Steps : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=s+i;
		printf("%d ",s);
	}
	return;
}
