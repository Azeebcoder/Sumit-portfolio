#include<stdio.h>
#include<math.h>
int main()
{
	int n,r,num=0,i;
	printf("\n\nEnter Bianary Number : ");
	scanf("%d",&n);
	for(i=0;n>0;i++)
	{
		r=n%10;
		if(r>1)
		{
			break;
		}
		num=num+(r*pow(2,i));
		n=n/10;
	}
	if(n<=0)
	{
		printf("\n\nThe decimal number is = %d\n\n",num);
	}
	else
	{
		printf("\n\nApne Binary Number Nahi Likha hai\n\n");
	}
	return 0;
}
