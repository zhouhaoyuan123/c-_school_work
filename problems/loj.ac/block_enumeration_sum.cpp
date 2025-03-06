#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int S = 316 + 5;
typedef long long ll;
ll a[N], sum[S], add[S];
int n, m, B;
int get(int x) {
	return (x + B - 1) / B;
}
int main() {
	cin >> n;
	B = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[get(i)] += a[i];
	}
	m = n;
	while (m--) {
		int op, l, r, x;
		cin >> op >> l >> r >> x;
		int idl = get(l),idr = get(r);
		if (op == 0) {
			if(idl == idr) {
				for(int i = l;i<=r;i++) {
					a[i] += x;
				}
				sum[idl] += (r - l + 1) * x;
			}
			else {
				for(int i = idl + 1;i <= idr - 1;i++) {
					add[i] += x;
				}
				for(int i = l;i<=idl * B;i++) {
					a[i] += x;
				}
				sum[idl] += (idl * B - l + 1) * x;
				for(int i = (idr - 1) * B + 1;i<=r;i++) {
					a[i] += x;
				}
				sum[idr] += (r - (idr - 1) * B) * x;
			}
		} else if (op == 1) {
			ll ans = 0;
			if(idl == idr) {
				for(int i = l;i<=r;i++) {
					ans += (a[i] % (x + 1) + add[idl] % (x + 1)) % (x + 1);
					ans %= (x + 1);
				}
			}
			else {
				for(int i = idl + 1;i<=idr - 1;i++) {
					ans += (sum[i] % (x + 1) + (add[i] % (x + 1) * (B % (x + 1))) % (x + 1)) % (x + 1);
					ans %= (x + 1);
				}
				for(int i = l;i<=idl * B;i++) {
					ans += ( a[i] % (x + 1) + add[idl] % (x + 1) ) % (x + 1);
					ans %= (x + 1);
				}
				for(int i = (idr - 1) * B + 1;i<=r;i++) {
					ans += (a[i] % (x + 1) + add[idr] % (x + 1)) % (x + 1);
					ans %= (x + 1);
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
