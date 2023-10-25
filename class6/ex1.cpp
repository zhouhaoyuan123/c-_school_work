#include <iostream>
using namespace std;
long long max_ = 0, cnt = 0, num;

void f(long long n) {
	if (cnt >= num) {
		return;
	}
	cout << n << endl;
	cnt++;
	if (max_ < n) {
		max_ = n;
	}
	f(2 * n + 1);
	f(3 * n + 1);
}

int main() {
	long long tmp;
	cin >> tmp;
	cin >> num;
	f(tmp);
	cout << max_ << endl;
	return 0;
}