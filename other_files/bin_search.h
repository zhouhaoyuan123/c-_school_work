void bin_search(int n, long long x) {
	int left = 0, right = n;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == num[mid]) {
			// �ҵ���
			cout << x << endl;
			return;
		} else if (x < num[mid]) {
			// �� [left, mid - 1] �м������� x��
			//int tmp = right;
			right = mid - 1;
			if (!(left <= right)) {
				cout << num[left] << endl;
				return;
			}
		} else {
			// �� [mid + 1, right] �м������� x��
			int tmp = left;
			left = mid + 1;
			if (!(left <= right)) {
				cout << num[tmp] << endl;
				return;
			}
		}
	}
}