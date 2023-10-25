#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	double x;
	int k;
	cin >> x >> k;
	int whole = x;
	double small = x - whole;
	stack<int> s;//整数
	queue<int> q;//小数
	while (whole != 0) {
		s.push(whole % k);
		whole /= k;
	}
	while (small < 1 && small != 0) {
		int t = small * k;
		q.push(t);
		small *= k;
	}
	while (!s.empty()) {
		if (s.top() >= 10) {
			cout << char(s.top() - 10 + 'A');
		} else {
			cout << s.top();
		}

		s.pop();
	}
	if (!q.empty()) {
		cout << ".";
	}
	while (!q.empty()) {
		if (q.front() >= 10) {
			cout << char(q.front() - 10 + 'A');
		} else {
			cout << q.front();
		}
		q.pop();
	}
	return 0;
}