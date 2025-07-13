#include<stdio.h>
int power(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	return a*power(a,b-1); 
}
int main()
{
	int a,b,c;
	printf("Enter A : ");
	scanf("%d",&a);
	printf("Enter B : ");
	scanf("%d",&b);
	c=power(a,b);
	printf("Answer : %d",c);
	return 0;
}
