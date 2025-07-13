#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isvalid(string s){
	stack<char> st;
	for(int i = 0;i < s.length();i++){
		char c=s[i];
		if(c=='('||c=='{'||c=='['){
			st.push(c);
		}
		else if(c==')'||c=='}'||c==']'){
			if(st.empty()){
				return false;
			}
			else{
				char t=st.top();
				st.pop();
				if((c==')'&&t!='(')||(c=='}'&&t!='{')||(c==']'&&t!='[')){
					return false;
				}
				
			}
		}
		
	}
	return st.empty();
}

int main(){
	string s="{[()]}[]}";
	cout<<isvalid(s);
	return 0;
}
