#include <iostream>
using namespace std;

struct node {
	long long data, l, r;
} bt[1000002];

bool is_bt (long long left, long long right) {
	if (left == -1 && right == -1)
		return true;
	else if (left == -1 || right == -1)
		return false;
	if (bt[left].data != bt[right].data)
		return false;
	return is_bt(bt[left].l, bt[right].r) && is_bt(bt[left].r, bt[right].l);
}

int count(int root) {
	return root == -1 ? 0 : count(bt[root].l) + count(bt[root].r) + 1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> bt[i].data;
	}
	for (int i = 1; i < n; i++) {
		cin >> bt[i].l >> bt[i].r;
	}
	cout << is_bt(1, 1);
	return 0;
}