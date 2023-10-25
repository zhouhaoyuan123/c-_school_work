#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[105], cnt[1005] = {0};
bool is_pick[1005] = {0};
int main() {
//   freopen("sum.in", "r", stdin);
	// freopen("sum.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i - 1; j++) {
			if (a[i] - a[j] >= 0 && a[i] - a[j] <= a[n - 1] && cnt[a[i] - a[j]] > 0 ) {
				if ((a[i] == a[i] - a[j] || a[j] == a[i] - a[j]) && cnt[a[i] - a[j]] <= 1) {
					continue;
				}
				ans++;
				cout << a[i] << " " << a[j] << " " << a[i] - a[j] << endl;
				break;
			}
		}
	}
	cout << ans ;
	return 0;
}