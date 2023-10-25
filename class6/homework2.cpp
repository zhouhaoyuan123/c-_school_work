#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	double sum[3] = {0}, cnt[3] = {0};
	cin >> n;
	char tmp[n];
	for (int i = 0; i < n; i++) {
		cin >> tmp[i];
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (tmp[i] == 'A') {
			sum[0] += t;
			cnt[0] ++;
		} else if (tmp[i] == 'B') {
			sum[1] += t;
			cnt[1] ++;
		} else {
			sum[2] += t;
			cnt[2] ++;
		}
	}
	for (int i = 0; i < 3; i++) {
		sum[i] /= cnt[i];
		cout << sum[i] << endl;
	}
	return 0;
}