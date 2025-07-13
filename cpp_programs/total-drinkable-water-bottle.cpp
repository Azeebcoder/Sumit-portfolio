#include<iostream>
using namespace std;
int total(int full,int change){
	if(full<change) return full;
	if(full>=change){
		int temp=full;
		while(temp>0){
			int save=temp%change;
			temp=temp/change;
			full=full+temp;
			if(save+temp>=change){
				temp=temp+save;
			}
		}
	}
	return full;
}

int main(){
	cout<<total(21,3)<<endl;
	return 0;
}
