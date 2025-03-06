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
	}
	m = n;
	while (m --) {
		int op, l, r, x;
		cin >> op >> l >> r >> x;
		int idl = get(l),idr = get(r);
		if (op == 0) {
			//cin >> x;
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
			cout << a[r] + add[idr] << endl;
		}
	}
	return 0;
}
