#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	string str;
	cin >> str;
	int l=str.length();
	int open=0, close=0;
	bool ans=true;
	for(int i=0; i<l; i++){
		if(str[i]=='(') open++;
		if(str[i]==')') close++;
		if(open<close){
			ans=false;
			break;
		}
	}
	if(open!=close) ans=false;
	if(ans) cout << "YES";
	else cout << "NO";
}
