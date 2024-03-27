#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ull;
bool isnum(char x){
	if(x>='0' && x<='9') return true;
	return false;
}
bool isop(char x){
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')')
		return true;
	return false;
}
int main(){
	string str;
	cin >> str;
	stack<ull> num;
	stack<ull> op;
	ull l=str.length();
	for(ull i=0; i<l; i++){
		if(isnum(str[i])){
			ull t=0;
			while(isnum(str[i])){
				t*=10;
				t+=(str[i]-'0');
				i++;
			}
			i--;
			num.push(t);
		}
		else if(isop(str[i])){
			if(str[i]=='+'){
				if(op.empty())
					op.push(1);
				else if(op.top()==0)
					op.push(1);
				else{
					while(op.size() && op.top()!=0){
						ull p, q;
						q=num.top();
						num.pop();
						p=num.top();
						num.pop();
						if(op.top()==1)
							num.push(p+q);
						else if(op.top()==2)
							num.push(p-q);
						else if(op.top()==3)
							num.push(p*q);
						else if(op.top()==4)
							num.push(p/q);
						op.pop();
					}
					op.push(1);
				}
			}
			else if(str[i]=='-'){
				if(op.empty())
					op.push(2);
				else if(op.top()==0)
					op.push(2);
				else{
					while(op.size() && op.top()!=0){
						ull p, q;
						q=num.top();
						num.pop();
						p=num.top();
						num.pop();
						if(op.top()==1)
							num.push(p+q);
						else if(op.top()==2)
							num.push(p-q);
						else if(op.top()==3)
							num.push(p*q);
						else if(op.top()==4)
							num.push(p/q);
						op.pop();
					}
					op.push(2);
				}
			}
			else if(str[i]=='*'){
				if(op.empty())
					op.push(3);
				else if(op.top()<3)
					op.push(3);
				else{
					while(op.size() && op.top()>=3){
						ull p, q;
						q=num.top();
						num.pop();
						p=num.top();
						num.pop();
						if(op.top()==3)
							num.push(p*q);
						else if(op.top()==4)
							num.push(p/q);
						op.pop();
					}
					op.push(3);
				}
			}
			else if(str[i]=='/'){
				if(op.empty())
					op.push(4);
				else if(op.top()<3)
					op.push(4);
				else{
					while(op.size() && op.top()>=3){
						ull p, q;
						q=num.top();
						num.pop();
						p=num.top();
						num.pop();
						if(op.top()==3)
							num.push(p*q);
						else if(op.top()==4)
							num.push(p/q);
						op.pop();
					}
					op.push(4);
				}
			}
			else if(str[i]=='('){
				op.push(0);
			}
			else if(str[i]==')'){
				while(op.size() && op.top()!=0){
					ull p, q;
					q=num.top();
					num.pop();
					p=num.top();
					num.pop();
					if(op.top()==1)
						num.push(p+q);
					else if(op.top()==2)
						num.push(p-q);
					else if(op.top()==3)
						num.push(p*q);
					else if(op.top()==4)
						num.push(p/q);
					op.pop();
				}
				if(op.top()==0)
					op.pop();
			}
		}
	}
	while(op.size()){
		ull p, q;
		q=num.top();
		num.pop();
		p=num.top();
		num.pop();
		if(op.top()==1)
			num.push(p+q);
		else if(op.top()==2)
			num.push(p-q);
		else if(op.top()==3)
			num.push(p*q);
		else if(op.top()==4)
			num.push(p/q);
		op.pop();
	}
	cout << num.top();
}
// 와, 코드 진짜 더럽다...
