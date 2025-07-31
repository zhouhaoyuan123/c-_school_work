#include <iostream>
using namespace std;
long long ans = 0;
int st[500010][25],lg[500010],depth[500010],t;
struct node {
	int from,to,next;
}ed[2 * 500010];
int v[2 * 500010],tot = 0;
void addedge(int x,int y) {
	ed[++tot].from = x;
	ed[tot].to = y;
	ed[tot].next = v[x];
	v[x] = tot;
}
int calc(int x,int y,int z,int t1) {
	int ans1 = abs(depth[t1] - depth[x]) + abs(depth[t1] - depth[y]) + abs(depth[t1] - depth[z]);
	return ans1;
}
void dfs(int u,int fa) {
	depth[u] = depth[fa] + 1;
	st[u][0] = fa;
	for(int i = 1;(1 << i) <= depth[u];i++) {
		st[u][i] = st[st[u][i - 1]][i - 1];
	}
	for(int i = v[u];i;i = ed[i].next) {
		if(ed[i].to == fa) continue;
		dfs(ed[i].to,u);
	}
}

int lca(int x,int y) {
	if(depth[x] < depth[y]) swap(x,y);
	while(depth[x] > depth[y]) {
		x = st[x][lg[depth[x] - depth[y]]];
	}
	if(x == y) return x;
	for(int i = lg[depth[x]];i>=0;i--) {
		if(st[x][i] != st[y][i]) {
			x = st[x][i];
			y = st[y][i];
		}
	}
	return st[x][0];
}

int main() {
	int n,m;
	cin>>n>>m;
	lg[1] = 0;
	for(int i = 2;i<=500000;i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for(int i = 1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	while(m --) {
		int x,y,z,k;
		cin>>x>>y>>z>>k;
		int tmp = lca(x,y),tmp2 = lca(z,k);
		int tmp3 = lca(x,z),tmp4 = lca(y,k);
		if((depth[tmp3] >= max(depth[tmp],depth[tmp2]) && depth[tmp3] <= min(depth[x],depth[z])) || (depth[tmp4] >= max(depth[tmp],depth[tmp2])&& depth[tmp3] <= min(depth[k],depth[y]))) {
			cout << "Y" << "\n";
		}
		else {
			cout << "N" << "\n";
		}
	}
	return 0;
}
