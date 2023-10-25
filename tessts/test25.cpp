#include <iostream>
using namespace std;
int cnt = 0;
int num, t;

void f(int n, int res) {
	//cout << n << " " << res << endl;
	if (res == 1) {
		cnt++;
		return;
	}
	if (n == res) {
		cnt++;
		return;
	}
	if (n > t || res < n) {
		return;
	}
	if (res % n != 0 || t % (res / n) != 0) {
		f(n + 1, res);
		return;
	}
	f(n + 1, res / n);
	f(n + 1, res);
	f(n, res / n);
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cnt = 0;
		cin >> t;
		f(2, t);
		cout << cnt << endl;
	}
	return 0;
}
