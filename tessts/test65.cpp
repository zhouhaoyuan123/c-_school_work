#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct line {
	int v,w;  
};
vector<line> G[10005];
bool vis[10005];
bool dfs(int node,int step,int lim,int end) {
	if(node == end) {
		return step <= lim;
	}
	vis[node] = true;
	bool judge = false;
	for(int i = 0;G[node].size();i++) {
		if(!vis[G[node][i].v]) {
			judge |= dfs(G[node][i].v,max(step,G[node][i].w),lim,end);
		}
	}
	vis[node] = false;
	return judge;
}

int main() {
//	freopen("rescue.in","r",stdin);
//	freopen("rescue.out","w",stdout);
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i = 1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	int l = 1,r = 1e4,ans = 0;
	while(l<=r) {
		int mid = (l+r) / 2;
		if(dfs(s,0,mid,t)) {
			ans = r;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
