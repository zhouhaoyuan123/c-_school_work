#include <iostream>
#include <stack>
using namespace std;

/*
stack b
a->max b
b.push
*/
int main() {
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op == 0) {
			int x;
			cin >> x;
			s.push(x);
		} else if (op == 1) {
			if (s.empty()) {
				continue;
			}
			s.pop();
		} else {
			if (s.empty()) {
				cout << 0 << endl;
				continue;
			}
			stack<int> tmp;
			int max = 0;
			while (!s.empty()) {
				if (max < s.top()) {
					max = s.top();
				}
				tmp.push(s.top());
				s.pop();
			}
			cout << max << endl;
			while (!tmp.empty()) {
				s.push(tmp.top());
				tmp.pop();
			}
		}
	}
	return 0;
}