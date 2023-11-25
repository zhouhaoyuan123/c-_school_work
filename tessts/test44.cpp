#include <iostream>
#include <cstdio>
using namespace std;
int maze[501][501];int n,m;int l[501],c[501],maxl,maxc;
void dfs(int x, int y) {
	if(maze[x][y] == 0) {
		return;
	}
	maze[x][y] = 0;l[x] --;c[y] --;
	for(int i = 0;i<n;i++) {
		dfs(i,y);
	}
	for(int i = 0;i<m;i++) {
		dfs(x,i);
	}
} 
bool findmax(int cnt) {
	if(cnt > 1) {
		return true;
	}
	bool flag = true;
	for(int i = 0;i<n;i++) {
		if(l[i] != 0) {
			flag = false;
			if(l[maxl] < l[i]) {
				maxl = i;
			}
		}
	}
	for(int i = 0;i<m;i++) {
		if(c[i] != 0) {
			flag = false;
			if(c[maxc] < c[i]) {
				maxc = i;
			}
		}
	}
	return flag;
}

int main() {
	//freopen("boom.in","r",stdin);freopen("boom.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			char tmp;cin>>tmp;
			maze[i][j] = tmp - '0';
			if(maze[i][j]) {
				l[i] ++;
				c[j] ++;
			}
		}
	}
	int ans = 0;
	int i = -1;
	while(!findmax(i++)) {
		ans++;
		dfs(maxl,maxc);
		maxl = 0,maxc = 0;
	}
	cout << ans;
	return 0;
}
