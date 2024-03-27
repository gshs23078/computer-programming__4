#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool valid(char x){
	if(x>='a' && x<='c') return true;
	return false;
}
int main(){
	string str;
	cin >> str;
	int l=str.length();
	while(!valid(str[l-1])) l--;
	stack<char> st1;
	stack<char> st2;
	for(int i=l-1; i>=0; i--)
		st1.push(str[i]);
	while(st1.size()>1){
		char prev=st1.top();
		st2.push(prev);
		st1.pop();
		while(st1.size() && st1.top()!=prev){
			prev=st1.top();
			st2.push(prev);
			st1.pop();
		}
		if(st1.size()){
			st1.pop();
			st2.pop();
			if(prev=='a')
				st1.push('b');
			else if(prev=='b')
				st1.push('c');
			else if(prev=='c')
				st1.push('a');
			while(st2.size()){
				st1.push(st2.top());
				st2.pop();
			}
		}
		else{
			while(st2.size()){
				st1.push(st2.top());
				st2.pop();
			}
			break;
		}
	}
	while(st1.size()){
		cout << st1.top();
		st1.pop();
	}
}
