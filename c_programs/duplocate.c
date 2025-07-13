#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter N : ");
	scanf("%d",&n);
	int array[n],array2[n];
	for(i = 0;i<n;i++)
	{
		printf("Enter %d Element : ",i+1);
		scanf("%d",&array[i]);
		array2[i]=array[i];
	}
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		int s = 1,k=0;
		for(j=i+1;j<n;j++)
		{
			if(array2[i]==0) break;
			if(array2[i]==array2[j])
			{
				k=array2[i];
				s++;
				array2[j]=0;
			}
		}
		if(k!=0)
		{
			printf("\n%d is %d times\n",k,s);
		}
	}
	return 0;
}
