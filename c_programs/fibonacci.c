#include<stdio.h>
int main()
{
	int n1=0,n2=1,n3,i,n;
	printf("Enter steps : ");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("\n\nKya Chaa Ra Bhai Tu");
	}
	if(n>0)
	{
		printf("%d ",n1);
	}
	if(n>1)
	{
		printf("%d ",n2);
	}
	for(i=3;i<=n;i++)
	{
		n3=n1+n2;
		printf("%d ",n3);
		n1=n2;
		n2=n3;
	}
	return 0;
}
