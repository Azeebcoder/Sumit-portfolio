#include<stdio.h>                                      
#include<stdlib.h>
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
	for(i=1;i<n-1;i++)
	{
		bool s = true;
		for(j=0;j<n-i;j++)
		{
			if(array[j]>array[j+1])
			{
				int temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
				s = false;
			}
		}
		if(s==true) break;
	}
	printf("\n\n\nSorted array = [ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("]\n\n");
	return 0;
}
