#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	scanf("%[^\n]s",str);
	int len=strlen(str)-1,i;
	while(len>=0){
		int end=len,st;
		while((str[len]!=' ')){
			if(len==0) break;
			len--;
			
		}
		if(len==0) st=len;
		else st=len+1;
		len--;
		for(i=st;i<=end;i++){
			printf("%c",str[i]);
		}
		printf(" ");
	}
	return 0;
}
