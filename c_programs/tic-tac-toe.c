#include<stdio.h>
void indexes(int p,int* r,int* c){
	int i,j,s=-1;
	for(i=0;i<3;i++){
		for(j=0;j<3;++j){
			s++;
			if(s==p-1){
				*r=i;
				*c=j;
				break;
			}
		}
		if(s==p-1){
			*r=i;
			*c=j;
			break;
		}
	}
	return;
}
int check(char game[3][3]){
	int i,j,a,b,aa,bb,aaa=0,bbb=0,aaaa=0,bbbb=0;
	for(i=0;i<3;i++){
		a=0,b=0,aa=0,bb=0;
		for(j=0;j<3;j++){
			if(game[i][j]=='O') a++;
			if(game[i][j]=='X') b++;
			if(game[j][i]=='O') aa++;
			if(game[j][i]=='X') bb++;
			if(i==j&&game[i][j]=='O') aaa++;
			if(i==j&&game[i][j]=='X') bbb++;
			if(i+j==2&&game[i][j]=='O') aaaa++;
			if(i+j==2&&game[i][j]=='X') bbbb++;
		}
		if(a==3||b==3||aa==3||bb==3||aaa==3||bbb==3||aaaa==3||bbbb==3) break;
	}
	if(a==3||aa==3||aaa==3||aaaa==3) return 1;
	else if(b==3||bb==3||bbb==3||bbbb==3) return 2;
	else return 0;
}
void chapdo(char game[3][3]){
	printf("\n\n\t\t  %c  |  %c  |  %c  \n",game[0][0],game[0][1],game[0][2]);
	printf("\t\t-----------------\n");
	printf("\t\t  %c  |  %c  |  %c  \n",game[1][0],game[1][1],game[1][2]);
	printf("\t\t------------------\n");
	printf("\t\t  %c  |  %c  |  %c  \n",game[2][0],game[2][1],game[2][2]);
	return;
}
int main(){
	int p1,p2,row,column,i,j,x,bazzi=0;
	char game[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	chapdo(game);
	while(1){
		printf("Player 1 : ");
		scanf("%d",&p1);
		bazzi++;
		indexes(p1,&row,&column);
		while((game[row][column]=='O'||game[row][column]=='X')){
			printf("Wrong input\nPlayer 1 : ");
			scanf("%d",&p1);
			indexes(p1,&row,&column);
		}
		game[row][column]='O';
		system("cls");
		chapdo(game);
		x = check(game);
		if(x==1||x==2||bazzi>=9) break;
		printf("Player 2 : ");
		scanf("%d",&p2);
		bazzi++;
		indexes(p2,&row,&column);
		while((game[row][column]=='O'||game[row][column]=='X')&&bazzi<9){
			printf("Wrong input\nPlayer 2 : ");
			scanf("%d",&p2);
			indexes(p2,&row,&column);
		}
		game[row][column]='X';
		system("cls");
		chapdo(game);
		x = check(game);
		if(x==1||x==2||bazzi>=9) break;
	}
	if(x>=1) printf("\n\n\t\tPlayer %d Wins!!\n\n",x);
	else printf("\n\n\t\tTie!!!\n\n");
	return 0;
}
