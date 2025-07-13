#include<stdio.h>
#include<stdbool.h>
int main()
{
	int n,i,j;
	printf("\n\nArray Sorting By SUMIT\n\n");
	printf("\n\nEnter Size Of Array : ");
	scanf("%d",&n);
	int array[n];
	for(i=0;i<n;i++)
	{
		printf("Enter %d Element : ",i+1);
		scanf("%d",&array[i]);
	}
	system("cls");
	printf("\nGiven array = [ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("]");
	for(i=0;i<n-1;i++)
	{
		int k=i,s=array[i];
		for(j=i;j<n;j++)
		{
			if(s>array[j])
			{
				s=array[j];
				k=j;
			}
		}
		int temp = array[i];
		array[i] = array[k];
		array[k] = temp;
	}
	printf("\n\n\nSorted array = [ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("]\n\n");
	return 0;
}
