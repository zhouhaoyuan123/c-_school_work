#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int G[110][110];
bool vis[110][110];
int n,m;
int dir[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
void dfs(int u,int v) {
	vis[u][v] = true;
	for (int i = 0; i < 4; i++) {
		int nu = u + dir[i][0];
		int nv = v + dir[i][1];
		if(!vis[nu][nv] && 1 <= nu && nu <= n && 1 <= nv && nv <= n && G[nu][nv] != -1) {
			dfs(nu,nv);
		}
	}
}
int main() {
	memset(G,-1,sizeof(G));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v,w;
		cin >> u >> v>>w;
		G[u][v] = w;
		G[v][u] = w;
	}
	int cnt = 0;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(!vis[i][j] && G[i][j] != -1) {
				cnt++;
				dfs(i,j);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
