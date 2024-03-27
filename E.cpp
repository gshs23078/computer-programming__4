#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
	string str;
	cin >> str;
	int l=str.length();
	int mult=1, ans=0;
	bool last=false, chk=true;
	stack<char> st;
	for(int i=0; i<l; i++){
		if(str[i]=='('){
			st.push(str[i]);
			mult*=2;
			last=false;
		}
		else if(str[i]=='['){
			st.push(str[i]);
			mult*=3;
			last=false;
		}
		else if(str[i]==')'){
			if(st.empty()){
				chk=false;
				break;
			}
			if(st.top()!='('){
				chk=false;
				break;
			}
			st.pop();
			if(!last) ans+=mult;
			mult/=2;
			last=true;
		}
		else if(str[i]==']'){
			if(st.empty()){
				chk=false;
				break;
			}
			if(st.top()!='['){
				chk=false;
				break;
			}
			st.pop();
			if(!last) ans+=mult;
			mult/=3;
			last=true;
		}
	}
	if(!st.empty()) chk=false;
	if(chk) cout << ans;
	else cout << "0";
}
