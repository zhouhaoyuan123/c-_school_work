#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int S = 316 + 5;
typedef long long ll;
ll a[N], add[S];
int n, m, B;
int get(int x) {
	return (x + B - 1) / B;
}
int main() {
	cin >> n >> m;
	B = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1;i<=n;i+=(B - 1)) {
		sort(a + i,a + min(i + B - 1,n + 1));
	}
	m = n;
	while (m--) {
		int op, l, r;
		long long x;
		cin >> op >> l >> r;
		int idl = get(l),idr = get(r);
		if (op == 0) {
			cin >> x;
			if(idl == idr) {
				for(int i = l;i<=r;i++) {
					a[i] += x;
				}
			}
			else {
				for(int i = idl + 1;i <= idr - 1;i++) {
					add[i] += x;
				}
				for(int i = l;i<=idl * B;i++) {
					a[i] += x;
				}
				for(int i = (idr - 1) * B + 1;i<=r;i++) {
					a[i] += x;
				}
			}
		} else if (op == 1) {
			cin>>x;
			x = x * x;
			ll ans = 0;
			if(idl == idr) {
				if(a[lower_bound(a + l,a + r,x) - a] < x - add[idl]) {
					ans += r - l + 1;
				}
				else ans += lower_bound(a + l,a + r,x - add[idl]) - a - l - 1;
			}
			else {
				for(int i = idl + 1;i<=idr - 1;i++) {
					ans += lower_bound(a + (i - 1) * B + 1,a + i * B,x - add[i]) - a - (i - 1) * B - 2;
				}
				ans += lower_bound(a + l,a + idl * B,x - add[idl]) - a - l - 1;
				ans += lower_bound(a + (idr - 1) * B + 1,a + r,x - add[idr]) - a - (idr - 1) * B - 1;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
