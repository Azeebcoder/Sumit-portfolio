#include<stdio.h>
#include<stdlib.h>
//matrix multiplication program

int main()
{
	printf("\n\n\t\t\tMatrix Multiply By Sumit\n\n\n\n");
	int r1,r2,c1,c2;
	printf("Enter first matrix row count : ");
	scanf("%d",&r1);
	printf("Enter first matrix column count : ");
	scanf("%d",&c1);
	printf("Enter second matrix row count : ");
	scanf("%d",&r2);
	printf("Enter second matrix column count : ");
	scanf("%d",&c2);
	system("cls");
	int matrix1[r1][c1],matrix2[r2][c2],res[r1][c2];
	int i,j,k,ele;
	if(c1==r2)
	{
		printf("\nEnter Elements of first matrix\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%d",&matrix1[i][j]);
			}
		}
		printf("\nEnter Elements of second matrix\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf("%d",&matrix2[i][j]);
			}
		}
		system("cls");
		printf("\n\n\n");
		for(i=0;i<r1;i++)
		{
			printf("\n\nRow %d elements => ",i+1);
			for(j=0;j<c2;j++)
			{
				ele=0;
				for(k=0;k<r2;k++)
				{
					ele=ele + matrix1[i][k]*matrix2[k][j];
				}
				res[i][j]=ele;
				printf("%d  ",res[i][j]);
			}
			printf("\n");
		}
	}
	else 
	{
		printf("\n\nMultipiclation not possible\n\n\n");
	}
	return 0;
}
