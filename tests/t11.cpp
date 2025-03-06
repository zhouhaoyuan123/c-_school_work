#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1001000;
struct node {
	int next, to;
} a[maxn * 2];
int h[maxn], tot = 0;
int n, m;
int id[maxn], vs[maxn], cnt = 0;
long long init[maxn], lazy[maxn * 4], val[maxn * 4];
int sum[maxn];
void dfs(int x, int fa) {
	cnt++;
	id[cnt] = x;
	vs[x] = cnt;
	sum[x] = 1;
	for (int i = h[x]; i != -1; i = a[i].next) {
		int to = a[i].to;
		if (to == fa) {
			continue;
		}
		dfs(to, x);
		sum[x] += sum[to];
	}
}
void pushdown(int rt, int l, int r) {
	if (lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		int mid = (l + r) >> 1;
		val[rt << 1] += lazy[rt] * (mid - l + 1);
		val[rt << 1 | 1] += lazy[rt] * (r - mid);
		lazy[rt] = 0;
	}
}
void pushup(int rt) {
	val[rt] = val[rt << 1] + val[rt << 1 | 1];
}
void update(int rt, int l, int r, int L, int R, int k) {
	if (l > R || r < L) {
		return;
	}
	if (L <= l && r <= R) {
		lazy[rt] = ! lazy[rt];
		val[rt] += k * (r - l + 1);
		val[rt] = abs(val[rt]);
		return;
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	update(rt << 1, l, mid, L, R, k);
	update(rt << 1 | 1, mid + 1, r, L, R, k);
	pushup(rt);
}
long long query(int rt, int l, int r, int L, int R) {
	if (l > R || r < L) {
		return 0;
	}
	if (L <= l && r <= R) {
		return val[rt];
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	return query(rt << 1, l, mid, L, R) + query(rt << 1 | 1, mid + 1, r, L, R);
}
void add(int x, int y) {
	a[++tot] = (node) {h[x], y};
	h[x] = tot;
}
int main() {
	scanf("%d%d",&n,&m);
	memset(h, -1, sizeof(h));
	for (int i = 1; i <= n; i++) {
		init[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		update(1, 1, n, vs[i], vs[i], init[i]);
	}
	for (int i = 1; i <= m; i++) {
		char type;
		int x, p;
		scanf("%c%d",&type,&x);
		if (type == 'C') {
			update(1,1,n,vs[x],vs[x],-1);
		}
		if (type == 'Q') {
			printf("%lld \n",query(1,1,n,vs[x],vs[x] + sum[x] - 1));
		}
	}
	return 0;
}
