#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
const int M = 20;
struct edge {
	int v;
};
struct Node {
	int depth;
};
vector<edge> G[N];
Node node[N];
int lg[N];
int st[N][M];
void dfs(int u,int v) { 
	st[u][0] = v;
	for(int i = 1;(1 << i) <= node[u].depth;i++) {
		st[u][i] = st[st[u][i - 1]][i - 1];
	}
	for(int i = 0;i<G[u].size();i++) {
		if(G[u][i].v != v) {
			node[G[u][i].v].depth = node[u].depth + 1;
			dfs(G[u][i].v,u);
		}
	}
}
bool cmp(Node x,Node y) {
	return x.depth < y.depth;
}
int LCA(int l,int r) {
	if(node[l].depth < node[r].depth) swap(l,r);
	while(node[l].depth > node[r].depth) {
		l = st[l][lg[node[l].depth - node[r].depth]];
	}
	if(l == r) return l;
	for(int i = lg[node[r].depth];i>=0;i--) {
		if(st[l][i] != st[r][i]) {
			l = st[l][i];
			r = st[r][i];
		}
	}
	return st[l][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	node[1].depth = 1;
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		G[a].push_back({b});
		G[b].push_back({a});
	}
	dfs(1,0);
	while(m --) {
		int x,y,z;
		cin>>x>>y>>z;
		int f1 = LCA(x,y);
		int f2 = LCA(x,z);
		if(f1 == f2) {
			f2 = LCA(y,z);
		}
		else if(node[f1].depth > node[f2].depth) swap(f1,f2);
		int c = node[x].depth + node[y].depth + node[z].depth - node[f2].depth - 2 * node[f1].depth;
		cout << f2 << " " << c << endl;
	}
	return 0;
}
