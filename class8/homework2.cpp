#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k; //数列，目标
	map<int, int> cnt;
	cnt[0] = 0;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		cnt[i] = cnt[i - 1] + tmp;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (cnt[j] - cnt[i - 1] == k) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << "No solution";
	return 0;
}