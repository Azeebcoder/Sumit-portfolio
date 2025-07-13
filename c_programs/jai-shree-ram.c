#include<stdio.h>
#include<string.h>
#include <time.h>

void delay(int n)
{
	clock_t a = clock();
	while (clock() < a + n);
}
int main()
{
	int baadlen,i,j,alen,namelen,k;
	char baad[100]=" ";
	char a[]=" abcdefghijklmnopqrstuvwxyz";
	char name[100]=" ";
	printf("Enter name : ");
	gets(name);
	alen=strlen(a);
	namelen=strlen(name);
	for(i=0;i<namelen;i++)
	{
		baadlen=strlen(baad);
		for(j=0;j<=alen;j++)
		{
			if(a[j-1]==name[i])
			{
				baad[i+1]=name[i];
				break;
			}
			for(k=1;k<baadlen;k++)
			{
				printf("%c",baad[k]);
//				delay(50);
			}
			printf("%c\n",a[j]);
			delay(50);
//			usleep(50000);
		}
	}
	return 0;
}
