#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool islet(char x){
	if(x>='a' && x<='z') return true;
	if(x>='A' && x<='Z') return true;
	return false;
}
int main(){
	string str;
	cin >> str;
	int l=str.length();
	stack<char> st;
	for(int i=0; i<l; i++){
		if(islet(str[i]))
			cout << str[i];
		else{
			if(str[i]=='+'){
				if(st.empty())
					st.push('+');
				else if(st.top()=='(')
					st.push('+');
				else{
					while(st.size() && st.top()!='('){
						cout << st.top();
						st.pop();
					}
					st.push('+');
				}
			}
			else if(str[i]=='-'){
				if(st.empty()){
					st.push('-');
				}
				else if(st.top()=='('){
					st.push('-');
				}
				else{
					while(st.size() && st.top()!='('){
						cout << st.top();
						st.pop();
					}
					st.push('-');
				}
			}
			else if(str[i]=='*'){
				if(st.empty())
					st.push('*');
				else if(st.top()=='(' || st.top()=='+' || st.top()=='-')
					st.push('*');
				else{
					while(st.size() && (st.top()!='(' && st.top()!='+' && st.top()!='-')){
						cout << st.top();
						st.pop();
					}
					st.push('*');
				}
			}
			else if(str[i]=='/'){
				if(st.empty())
					st.push('/');
				else if(st.top()=='(' || st.top()=='+' || st.top()=='-')
					st.push('/');
				else{
					while(st.size() && (st.top()!='(' && st.top()!='+' && st.top()!='-')){
						cout << st.top();
						st.pop();
					}
					st.push('/');
				}
			}
			else if(str[i]=='('){
				st.push('(');
			}
			else if(str[i]==')'){
				while(st.top()!='('){
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
}
// H도 동일
