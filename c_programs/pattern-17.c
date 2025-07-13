#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,n;
	printf("Enter n : ");
	scanf("%d",&n);
	for(i=n;i>=-n;i--)
	{
		for(j=1;j<=abs(i)+1;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
