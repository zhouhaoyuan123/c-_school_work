#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int bin_search(int num[], int n, int x) {
	int left = 0, right = n;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == num[mid]) {
			// 找到了
			return 0;
		} else if (x < num[mid]) {
			// 在 [left, mid - 1] 中继续查找 x。
			//int tmp = right;
			int tmp = right;
			right = mid - 1;
			if (!(left <= right)) {
				if (right < 0) {
					return min(abs(num[left] - x), abs(num[tmp] - x));
				}
				return min(abs(num[right] - x), abs(num[left] - x));
			}
		} else {
			// 在 [mid + 1, right] 中继续查找 x。
			int tmp = left;
			left = mid + 1;
			if (!(left <= right)) {
				if (left >= n) {
					return min(abs(num[tmp] - x), abs(num[right] - x));
				}
				return min(abs(num[left] - x), abs(num[right] - x));
			}
		}
	}
}

int main() {
//    freopen("exam.in","r",stdin);
//    freopen("exam.out","w",stdout);
	int m, n;
	cin >> m >> n;
	int school[m], student[n];
	for (int i = 0; i < m; i++) {
		cin >> school[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> student[i];
	}
	int ans = 0;
	sort(school, school + m);
	for (int i = 0; i < n; i++) {
		ans += bin_search(school, m - 1, student[i]);
	}
	cout << ans;
	return 0;
}