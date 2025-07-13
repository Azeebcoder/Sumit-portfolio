#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int game(int x,int y);
int main()
{
    int comp,you,a,n,i,comp_won=0,you_won=0,g_left,tie_=0;
    printf("\n\n\t\t\t\t\tHow Many games you want to play : ");
    scanf("%d",&n);
    system("cls");
    g_left=n;
    for(i=1;i<=n;i++)
    {
    	srand(time(NULL));
    	comp=rand()%3+1;
    	system("cls");
    	printf("\n\t\t\t\t1 for Rock\t2 for Paper\t3 for Secissor\n\n\t\t\t\t");
    	scanf("%d",&you);
    	system("cls");
    	a=game(comp,you);
    	if(a==0)
	    {
	    	printf("\n\n\t\t\t\tYou Win !");
	    	you_won++;
		}
		else if(a==1)
	    {
	    	printf("\n\n\t\t\t\tYou Lose !");
	    	comp_won++;
		}
		else if(a==2)
	    {
	    	printf("\n\n\t\t\t\tTie !");
	    	tie_++;
		}
		if(comp==1)
		{
			printf("\tComputer Choose : Rock");
		}
		else if(comp==2)
		{
			printf("\tComputer Choose  : Paper");
		}
		else if(comp==3)
		{
			printf("\tComputer Choose : Secissor");
		}
		if(you==1)
		{
			printf("\tYou Choose : Rock");
		}
		else if(you==2)
		{
			printf("\tYou Choose : Paper");
		}
		else if(you==3)
		{
			printf("\tYou Choose : Secissor");
		}
		printf("\n\n\n\n\n\t\t\t\tYou Won : %d\tComputer Won : %d\tTied Games : %d\n\n\t\t\t\t\t",you_won,comp_won,tie_);
		g_left--;
		printf("\n\n\n\t\t\t\t\t\tGames left : %d",g_left);
		getch();
		system("cls");
	}
	if(comp_won>you_won)
	{
		printf("\n\n\n\t\t\t\t\tYou Lose by %d points\n\n\n\n",comp_won-you_won);
	}
	else if(comp_won<you_won)
	{
		printf("\n\n\n\t\t\t\t\tYou Win by %d points\n\n\n\n",you_won-comp_won);
	}
	if(comp_won==you_won)
	{
		printf("\n\n\n\t\t\t\t\tGame Tied\n\n\n\n");
	}
    return 0;
}
int game(int x,int y)
{
	if((x==1&&y==2)||(x==2&&y==3)||(x==3&&y==1))
	{
		return 0;
	}
	else if((x==1&&y==3)||(x==2&&y==1)||(x==3&&y==2))
	{
		return 1;
	}
	else if (x==y)
	{
		return 2;
	}
}
