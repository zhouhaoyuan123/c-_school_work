#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+50;
ll lazy[N * 4], val[N * 4], a[N];
int d;
void pushup(int rt) {
	val[rt] = max(val[rt * 2] , val[rt * 2 + 1]);
}
void update(int rt, int l, int r, int L, int R, int k) {
	if (l > R || r < L) {
		return;
	}
	if (l > R || r < L) {
		return;
	}
	if (L <= l && r <= R) {
		val[rt] = k;
		val[rt] %= d;
		return;
	}
	int mid = (l + r) / 2;
	update(rt * 2, l, mid, L, R, k);
	update(rt * 2 + 1, mid + 1, r, L, R, k);
	pushup(rt);
}
ll query(int rt, int l, int r, int L, int R) {
	if(l > R || r < L) {
		return 0;
	}
	if(L <= l && r <= R) {
		return val[rt];
	}
	int mid = (l + r) / 2;
	return max(query(rt * 2,l,mid,L,R) , query(rt * 2 + 1,mid + 1,r,L,R));
}
int main() {
	int m;
	cin>>m>>d;
	int tot = 0;
	int t = 0;
	while (m--) {
		char op;
		ll n;
		cin>>op>>n;
		if(op == 'A') {
			++tot;
			n %= d;
			n += t;
			n %= d;
			//cout << n << endl;
			update(1,1,tot,tot,tot,n);
		}
		else {
			t = query(1,1,tot,tot - n + 1,tot);
			cout << t << endl;
		}
	}
	return 0;
}
