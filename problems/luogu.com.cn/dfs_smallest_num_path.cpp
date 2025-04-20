#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> tree[200005];
vector <int> ans[200005];
int root = 0;
int n;
int res = 1;
void dfs(int u,int cnt) {
	ans[cnt].push_back(u);
	if(tree[u].size() >= 1) {
		dfs(tree[u][0],cnt);
	}
	for(int i = 1;i<tree[u].size();i++) {
		res ++;
		dfs(tree[u][i],res);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t --) {
		cin>>n;
		for(int i = 1;i<=n;i++) {
			tree[i].clear();
			ans[i].clear();
		}
		root = 0;
		res = 1;
		for(int i = 1;i<=n;i++) {
			int x;
			cin>>x;
			if(x == i) {
				root = i;
			}
			else {
				tree[x].push_back(i);
			}
		}
		dfs(root,1);
		cout << res << endl;
		for(int i = 1;i<=res;i++) {
			cout << ans[i].size() << endl;
			for(int j = 0;j<ans[i].size();j++) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
