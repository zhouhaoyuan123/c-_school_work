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
		int x,y,z;
		cin>>x>>y>>z;
		int t1 = lca(x,y);
		int t2 = lca(y,z);
		int t3 = lca(z,x);
//		if(t1 == t2)
//			t = t3;
//		else if(t1 == t3)
//			t = t2;
//		else if(t2 == t3)
//			t = t1;
//		int ans1 = calc(x,y,z,t1);
//		int ans2 = calc(x,y,z,t2);
//		int ans3 = calc(x,y,z,t3);
		int tmp = depth[t1],index = t1;
		if(tmp < depth[t2]) {
			index = t2;
			tmp = depth[t2];
		}
		if(tmp < depth[t3]) {
			index = t3;
			tmp = depth[t3];
		}
		cout << index << " " << depth[x] + depth[y] + depth[z] - depth[t1] - depth[t2] - depth[t3] << "\n";
		//int ans = min(,min(,));
//		int ans = depth[x] + depth[y] + depth[z] - depth[t1] - depth[t2] - depth[t3];
//		cout << t << " " << ans << "\n";
	}
	cout << endl;
	return 0;
}
