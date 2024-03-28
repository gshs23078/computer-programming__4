#include <iostream>
#include <stack>
#include <vector>
#define forf(i, a, b) for(int i=a;i<b;i++)
using namespace std;
int map[5][5];
void rot(int n){
// 시계 방향 90도씩 n번 회전 
	while(n--){
		int nwmap[5][5];
		for(int i=1; i<=4; i++)
			for(int j=1; j<=4; j++)
				nwmap[j][5-i]=map[i][j];
		for(int i=1; i<=4; i++)
			for(int j=1; j<=4; j++)
				map[i][j]=nwmap[i][j];
	}
	return;
}
int main(){
	int n, i, j;
	cin >> n;
	for(i=1; i<=4; i++)
		for(j=1; j<=4; j++)
			cin >> map[i][j];
	while(n--){
		int w, x, y, c;
		cin >> w >> x >> y >> c;
		rot(w-1);
		for(j=1; j<=4; j++){
			stack<int> st;
			for(i=1; i<=4; i++){
				if(map[i][j]==0)
					continue;
				if(st.empty())
					st.push(map[i][j]);
				else if(st.top()!=map[i][j])
					st.push(map[i][j]);
				else{
					st.push(map[i][j]);
					while(1){
						if(st.size()<=1) break;
						int p=st.top();
						st.pop();
						if(st.top()!=p){
							st.push(p);
							break;
						}
						st.pop();
						st.push(p*2);
					}
				}
			}
			int l=st.size();
			for(i=l; i>=1; i--){
				map[i][j]=st.top();
				st.pop();
			}
			for(i=l+1; i<=4; i++)
				map[i][j]=0;
		}
		rot(5-w);
		map[x][y]=c;
	}
	for(i=1; i<=4; i++){
		for(j=1; j<=4; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}
