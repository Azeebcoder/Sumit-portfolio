#include"bits\stdc++.h"
using namespace std;
int main(){
	vector<int> s;
	int n,i=0;
	do{
		cin>>n;
		if(n=='a') break;
		s.push_back(n);
		i++;
	}while(n!='a');
	for(i=0;i<s.size();i++){
		cout<<" "<<s[i];
	}
	return 0;
}
