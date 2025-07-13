#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j;
	printf("Enter How Many Names you want to Enter : ");
	scanf("%d",&n);
	char name[n][20];
	for(i=0;i<n;i++){
		printf("Enter %d Name : ",i+1);
		scanf("%s",name[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;i<n;i++){
			if(name[i][0]>=name[j][0]){
				char temp[20]="\0";
				strcpy(temp,name[j]);
				strcpy(name[j],name[i]);
				strcpy(name[i],temp);
			}
			
		}
		
	}
	for(i=0;i<n;i++){
		printf("%s ",name[i]);
	}
	return 0;
}
