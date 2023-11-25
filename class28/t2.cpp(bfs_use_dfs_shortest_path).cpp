#include <iostream>
using namespace std;
int n,m,s,t,cnt = 2e5 + 1;int G[5005][5005];int vis[5005];
void dfs(int u,int len) {
	if(u == t) {
		if(len < cnt) {
			cnt = len;
		}
		vis[u] = 0;
		return;
	}
	vis[u] = 1;
	for(int i = 1;i<=n;i++) {
		if(!vis[i] && G[u][i]) {
			dfs(i,len+1);
		}
	}
	vis[u] = 0;
}

int main() {
	cin>>n>>m>>s>>t;
	for(int i = 0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	dfs(s,0);
	if(cnt == 2e5 + 1) {
		cout << "No path";
		return 0;
	}
	cout << cnt;
	return 0;
}
