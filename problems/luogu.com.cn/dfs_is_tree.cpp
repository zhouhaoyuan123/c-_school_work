#include <bits/stdc++.h>
using namespace std;
vector <int> G[5005];
bool vis[5005];
bool flag = 1;
int cnt = 0;
void dfs(int u,int v) {
	if(!flag) return;
	cnt ++;
	vis[u] = true;
	for(int i = 0;i<G[u].size();i++) {
		if(vis[G[u][i]] && G[u][i] != v) {
			flag = 0;
			break;
		}
		if(G[u][i] == v) continue;
		dfs(G[u][i],u);
	}
}

int main() {
	int t;
	cin>>t;
	while(t --) {
		flag = 1;
		cnt = 0;
		memset(vis,0,sizeof(vis));
		int n,m;
		cin>>n>>m;
		for(int i = 1;i<=n;i++) {
			G[i].clear();
		}
		for(int i = 1;i<=m;i++) {
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(n - 1 != m) {
			cout << "not tree" << endl;
			continue;
		}
		dfs(1,1);
		if(cnt != n) {
			cout << "not tree" << endl;
			continue;
		}
		if(!flag) {
			cout << "not tree" << endl;
			continue;
		}
		cout << "tree" << endl;
	}
}
