#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n;
	cin >> n;
	int h;
	int max=0, idx=0;
	stack<int> st;
	for(int i=0; i<n; i++){
		cin >> h;
		if(st.empty()) st.push(h);
		else{
			while(st.size() && st.top()<=h){
				st.pop();
			}
			if(max<st.size()){
				max=st.size();
				idx=i;
			}
			st.push(h);
		}
	}
	cout << idx+1 << " " << max;
}
