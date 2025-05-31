#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int G[1005][1005];
int dp[1005];
int a[1005],b[1005];
bool vis[1005];
int n;
void dfs(int u) {
	vis[u] = true;
	for(int i = 1;i<=n;i++) {
		if(!G[u][i]) continue;
		if(!vis[i]) {
			dfs(i);
		}
		dp[u] = max(dp[u],1 + dp[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t --) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		cin>>n;
		for(int i = 1;i<=n;i++) {
			int x,y;
			cin>>x>>y;
			a[i] = min(x,y);
			b[i] = max(x,y);
		}
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=n;j++) {
				if(i == j) continue;
				if(a[i]<a[j] && b[i] < b[j]) {
					G[j][i] = 1;
				}
			}
			dp[i] = 1;
		}
		int ans = 1;
		for(int i = 1;i<=n;i++) {
			if(!vis[i]) {
				dfs(i);
			}
			ans = max(dp[i],ans);
		}
		cout << ans << endl;
	}
	return 0;
}
