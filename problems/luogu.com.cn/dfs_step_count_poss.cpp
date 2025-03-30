#include <iostream>
#include <vector>
using namespace std;
bool dp[505][25][505];
vector<int> tree[505];

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for(int i = 1;i<=n;i++) {
		dp[i][0][i] = 1;
	}
	for(int i = 1;i<=k;i++) {
		for(int j = 1;j<=n;j++) {
			for(int k = 0;k<tree[j].size();k++) {
				for(int z = 1;z <= n;z ++) {
					dp[j][i][z] |= dp[tree[j][k]][i - 1][z];
				}
			}
			
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=k;j++) {
			int ans = 0;
			for(int k = 1;k <= n;k++) {
				ans += dp[i][j][k];
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
