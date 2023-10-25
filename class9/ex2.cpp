#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		double cnt = 0, cnt2 = n + m;
		set <int> s1;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			s1.insert(t);
		}
		for (int i = 0; i < max(n, m); i++) {
			int t;
			cin >> t;
			if (s1.count(t)) {
				cnt++;
				cnt2 -= 2;
			}
			//s2.insert(t);
		}
		cnt /= (cnt + cnt2);
		cnt *= 100;
		cout << fixed << setprecision(0) << cnt << endl;
	}
	return 0;
}