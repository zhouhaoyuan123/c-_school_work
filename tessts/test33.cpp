#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main() {
	//freopen("restaurant.in","r",stdin);
	//freopen("restaurant.out","w",stdout);
	int n, q;
	cin >> n >> q;
	map<int, int> m, m2,m3;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		m[tmp] = 1;
		m2[tmp] = i;
		m3[i] = tmp;
	}
	for (int i = 0; i < q; i++) {
		char op[3];
		int x;
		cin >> op;
		cin >> x;
		if (op[0] == 'i') {
			auto res = m.lower_bound(x);
			if (res != m.end()) {
				cout << m2[res->first] << endl;
				m.erase(res->first);
			} else {
				cout << -1 << endl;
			}
		} else {
			m[m3[x]] = 1;
		}
	}
	return 0;
}
