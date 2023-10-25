void bin_search(int n, long long x) {
	int left = 0, right = n;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == num[mid]) {
			// 找到了
			cout << x << endl;
			return;
		} else if (x < num[mid]) {
			// 在 [left, mid - 1] 中继续查找 x。
			//int tmp = right;
			right = mid - 1;
			if (!(left <= right)) {
				cout << num[left] << endl;
				return;
			}
		} else {
			// 在 [mid + 1, right] 中继续查找 x。
			int tmp = left;
			left = mid + 1;
			if (!(left <= right)) {
				cout << num[tmp] << endl;
				return;
			}
		}
	}
}