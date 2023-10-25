#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		bool flag = true;
		int j = 0;
		while (j < q.size()) {
			int t2 = q.front();
			if (t2 == tmp) {
				flag = false;
			}
			q.pop();
			q.push(t2);
			j++;
		}
		if (flag) {
			q.push(tmp);
		}
		if (q.size() > m) {
			q.pop();
		}
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}