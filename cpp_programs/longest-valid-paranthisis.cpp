#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int longestvalid(string s){
	int res=0,current=0;
	stack<char> st;
	for(int i=0;i<s.size();i++){
		if(st.empty()){
			if(s[i]==')'){
				if(res<current){
					res=current;
				}
				current=0;
			}
			else{
				st.push(s[i]);
			}
		}
		else{
			if(s[i]==')'){
				st.pop();
				current=current+2;
			}
			else{
				st.push(s[i]);
			}
		}
	}
	if(res==0) return current;
	if(st.empty()&&current>res||!st.empty()&&current>res) return current;
	else return res;
}

int main(){
	cout<<longestvalid(")(()))()()())");
	return 0;
}
