#include<stdio.h>
int find(int arr[],int l,int h){
	int i=l,j=h;
	while(i<j){
		while(arr[l]>=arr[i]&&i<h&&i<j) i++;
		while(arr[l]<=arr[j]&&j>l&&j>i) j--;
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	int temp=arr[l];
	arr[l]=arr[j];
	arr[j]=temp;
	return j;
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
	find(arr,0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
