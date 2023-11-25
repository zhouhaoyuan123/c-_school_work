#include <cstdio>
#include <vector>
using namespace std;
vector<int> G[100005];
int vis[100005];
int dfs(int u) {
	int sum = 0;
	for(int i = 0;i<G[u].size();i++) {
		sum += dfs(G[u][i]);
	}
	vis[u] = sum;
	return sum + 1;
}

int main() {
//	freopen("family.in","r",stdin);
//	freopen("family.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i = 0;i<n;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
	}
	for(int i = 1;i<=n;i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	for(int i = 1;i<=n;i++) {
		printf("%d",vis[i]);
	}
	return 0;
}
