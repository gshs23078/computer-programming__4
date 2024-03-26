#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;
struct arr{
	int val;
	int idx;
};
bool cmp(arr a1, arr a2){
	return a1.val<a2.val;
}
int main(){
	ios::sync_with_stdio(false);
	int n, max=0;
	cin >> n;
	bool chk=true;
	stack<int> st;
	vector<string> ans;
	string str;
	cin >> str;
	arr a[n];
	for(int i=0; i<n; i++){
		a[i].val=str[i]-'0';
		a[i].idx=i+1;
	}
	sort(a, a+n, cmp);
	for(int i=0; i<n; i++){
		for(int j=max+1; j<=a[i].idx; j++){
			st.push(j);
			if(max<j) max=j;
			ans.push_back("push");
		}
		if(st.top()==a[i].idx){
			st.pop();
			ans.push_back("pop");
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
	else cout << "-1";
}
