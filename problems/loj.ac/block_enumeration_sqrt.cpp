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
					sum[idl] -= a[i];
					a[i] = sqrt(a[i]);
					sum[idl] += a[i];
				}
			}
			else {
				for(int i = idl + 1;i <= idr - 1;i++) {
					add[i] ++;
				}
				for(int i = l;i<=idl * B;i++) {
					sum[idl] -= a[i];
					a[i] = sqrt(a[i]);
					sum[idl] += a[i];
				}
				for(int i = (idr - 1) * B + 1;i<=r;i++) {
					sum[idr] -= a[i];
					a[i] = sqrt(a[i]);
					sum[idr] += a[i];
				}
			}
		} else if (op == 1) {
			ll ans = 0;
			if(idl == idr) {
				for(int i = l;i<=r;i++) {
					int tmp = a[i];
					for(int i = 1;i<=add[idl];i++) {
						if(tmp <= 1) break;
						tmp = sqrt(tmp);
					}
					ans += tmp;
				}
			}
			else {
				for(int i = idl + 1;i<=idr - 1;i++) {
					for(int j = (i - 1) * B + 1;j<=i * B;j++) {
						int tmp = a[j];
						for(int k = 1;k<=add[i];k++) {
							if(tmp <= 1) break;
							tmp = sqrt(tmp);
						}
						ans += tmp;
					}
					add[i] = 0;
				}
				for(int i = l;i<=idl * B;i++) {
					int tmp = a[i];
					for(int k = 1;k<=add[idl];k++) {
						if(tmp <= 1) break;
						tmp = sqrt(tmp);
					}
					ans += tmp;
				}
				for(int i = (idr - 1) * B + 1;i<=r;i++) {
					int tmp = a[i];
					for(int k = 1;k<=add[idr];k++) {
						if(tmp <= 1) break;
						tmp = sqrt(tmp);
					}
					ans += tmp;
				}
				add[idl] = 0,add[idr] = 0;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
