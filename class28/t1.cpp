#include <iostream>
using namespace std;
int n,m,s,t,cnt;int G[101][101];int vis[101];
void dfs(int u) {
	if(u == t) {
		cnt++;
		vis[u] = 0;
		return;
	}
	vis[u] = 1;
	for(int i = 1;i<=n;i++) {
		if(!vis[i] && G[u][i]) {
			dfs(i);
		}
	}
	vis[u] = 0;
}

int main() {
	cin>>n>>m>>s>>t;
	for(int i = 0;i<m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		G[x][y] = 1;
	}
	dfs(s);
	if(cnt == 0) {
		cout << -1;
		return 0;
	}
	cout << cnt;
	return 0;
}
