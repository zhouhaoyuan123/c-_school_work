#include <bits/stdc++.h>
using namespace std;
vector<int> G[1005];
bool isleaf[1005];
bool flag = 1;
void dfs(int u) {
	if(!flag) return;
	int ans = 0;
	for(int i = 0;i<G[u].size();i++) {
		ans += isleaf[G[u][i]];
		if(!isleaf[G[u][i]]) {
			dfs(G[u][i]);
		}
	}
	if(ans < 3) {
		flag = false;
	}
}
int main() {
	int n;
	cin>>n;
	memset(isleaf,1,sizeof(isleaf));
	for(int i = 2;i<=n;i++) {
		int v;
		cin>>v;
		isleaf[v] = false;
		G[v].push_back(i);
	}
	dfs(1);
	if(flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
