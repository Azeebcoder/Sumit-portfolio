#include<iostream>
#include<stack>
#include<deque>
#include<vector>
using namespace std;

void maxinwindow(vector<int> &arr){
	deque<int> de;
	int i=0;
	while(i<3){
		if(!de.empty()){
			while(!de.empty()&&arr[i]>arr[de.back()]){
				de.pop_back();
			}
		}
		de.push_back(i);
		i++;
	}
	cout<<arr[de.front()]<<" ";
	
	while(i<arr.size()){
		if(i-de.front()>=3){
			de.pop_front();
		}
		if(!de.empty()){
			while(!de.empty()&&arr[i]>arr[de.back()]){
				de.pop_back();
			}
		}
		de.push_back(i);
		i++;
		cout<<arr[de.front()]<<" ";
	}
}

int main(){
	vector<int>arr;
	arr.push_back(5);
	arr.push_back(32);
	arr.push_back(1);
	arr.push_back(0);
	arr.push_back(-51);
	arr.push_back(4);
	arr.push_back(9);
	arr.push_back(1);
	arr.push_back(0);
	arr.push_back(5);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	maxinwindow(arr);
	return 0;
}
