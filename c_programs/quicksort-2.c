#include<stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int find(int arr[],int l,int h){
	int i=l+1,j=h;
	do{
		while(arr[l]>=arr[i]&&i<=h) i++;
		while(arr[l]<=arr[j]&&j>l) j--;
		if(i<j) swap(&arr[i],&arr[j]);
	}while(i<j);
	swap(&arr[l],&arr[j]);
	return j;
}
void quicksort(int arr[],int l,int h){
	if(l<h){
		int pi=find(arr,l,h);
		quicksort(arr,l,pi-1);
		quicksort(arr,pi+1,h);
	}
	return;
}
int main(){
	int n,i;
	printf("Enter Arrray size : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
