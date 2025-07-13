#include<stdio.h>
int main()
{
	int i,j,n1,n2,s;
	printf("Enter range\nFrom : ");
	scanf("%d",&n1);
	printf("To : ");
	scanf("%d",&n2);
	for(i=n1;i<=n2;i++)
	{
		s=0;
		for(j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				s++;
			}
		}
		if(s==2)
		{
			printf("%d  ",i);
		}
	}
	return 0;
}
