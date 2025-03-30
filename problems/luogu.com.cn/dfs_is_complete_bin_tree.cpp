#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int tree[100005][3];
int sequence[100005];
bool vis [100005];
int maxdepth;
bool flag = 1;
void dfs(int step,int u,int index) {
	if(u == 0) return;
	if(!flag) return;
	if(vis[u]) {
		flag = 0;
		return;
	}
	sequence[index] = u;
	vis[u] = true;
	maxdepth = max(maxdepth,step);
	dfs(step + 1,tree[u][1],index * 2);
	dfs(step + 1,tree[u][2],index * 2 + 1);
}
int main() {
	int t;
	cin>>t;
	while(t --) {
		memset(tree,0,sizeof(tree));
		memset(sequence,0,sizeof(sequence));
		memset(vis,0,sizeof(vis));
		maxdepth = 0;
		int n;
		cin>>n;
		for(int i = 1;i<=n;i++) {
			int x;
			cin>>x;
			cin>>tree[x][1]>>tree[x][2];
		}
		flag = 1;
		dfs(1,1,1);
		if(!flag) {
			cout << "No" << endl;
			continue;
		}
		int tmp = pow(2,maxdepth) - 1;
		flag = 1;
		for(int i = tmp;i>n;i--) {
			if(sequence[i] != 0) {
				cout << "No"<<endl;
				flag = false;
				break;
			}
		}
		if(flag) cout << "Yes" << endl;
	}
	return 0;
}
