#include<stdio.h>
int main()
{
	int i,n,s;
	printf("Enter Steps : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s=i*i;
		printf("%d ",s);
	}
	return 0;
}
