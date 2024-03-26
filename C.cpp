#include <iostream>
#include <stack>
#include <vector>
#define endl "\n"
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n, k, max=0;
	cin >> n;
	bool chk=true;
	stack<int> st;
	vector<char> ans;
	for(int i=0; i<n; i++){
		cin >> k;
		for(int j=max+1; j<=k; j++){
			st.push(j);
			if(max<j) max=j;
			ans.push_back('+');
		}
		if(st.top()==k){
			st.pop();
			ans.push_back('-');
			continue;
		}
		else{
			chk=false;
			break;
		}
	}
	if(chk){
		int l=ans.size();
		for(int i=0; i<l; i++)
			cout << ans[i] << endl;
	}
	else cout << "NO";
}
