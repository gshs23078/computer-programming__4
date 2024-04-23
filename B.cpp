#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	int open[3]={0}, close[3]={0};
	bool ans=true;
	string str;
	cin >> str;
	int l=str.length();
	stack<int> st;
	for(int i=0; i<l; i++){
		if(str[i]=='(')
			st.push(1);
		else if(str[i]=='[')
			st.push(2);
		else if(str[i]=='{')
			st.push(3);
		else if(str[i]==')'){
			if(st.size() && st.top()==1)
				st.pop();
			else{
				ans=false;
				break;
			}
		}
		else if(str[i]==']'){
			if(st.size() && st.top()==2)
				st.pop();
			else{
				ans=false;
				break;
			}
		}
		else if(str[i]=='}'){
			if(st.size() && st.top()==3)
				st.pop();
			else{
				ans=false;
				break;
			}
		}
	}
	if(!st.empty()) ans=false;
	if(ans) cout << "O";
	else cout << "X";
}
