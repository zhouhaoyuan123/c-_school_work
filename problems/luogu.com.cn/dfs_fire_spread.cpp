#include <iostream>
#include <vector>
using namespace std;
int n;
int ans[100005];
int w[100005];
bool vis[100005];
vector<int> tree[100005];
int dfs(int u,int v) {
	vis[u] = true;
	for(int i = 0;i<tree[u].size();i++) {
		if(tree[u][i] == v) continue; 
		if(!vis[tree[u][i]]) {
			ans[u] += dfs(tree[u][i],u);
		}
		else {
			ans[u] += ans[tree[u][i]];
		}
	}
	ans[u] ++;
	return ans[u];
}
int main() {
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>w[i];
	}
	for(int i = 1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		if(w[x] > w[y]) {
			tree[x].push_back(y);
		}
		else if(w[x] < w[y]) {
			tree[y].push_back(x);
		}
	}
	int sum = 0;
	for(int i = 1;i<=n;i++) {
		if(!vis[i]) {
			dfs(i,i);
		}
		sum = max(sum,ans[i]);
	}
	cout << sum << endl;
	return 0;
}
