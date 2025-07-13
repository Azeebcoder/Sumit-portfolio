#include<stdio.h>
int main()
{
	long long int i,r,n,n1=1,k,n2,c;
	printf("Enter Steps : ");
	scanf("%lli",&n);
	for(i=1;i<=n;i++)
	{
		printf("%lli ",n1);
		k=1;
		n2=0;
		while(n1!=0)
		{
			c=1;
			r=n1%10;
			n1=n1/10;
			while(r==n1%10)
			{
				c++;
				n1=n1/10;
			}
			n2=((10*c+r)*k)+n2;
			k=k*100;
		}
		
		n1=n2;
	}
	return 0;
}
