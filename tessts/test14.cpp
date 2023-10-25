#include <iostream>
#include <queue>
using namespace std;

struct p {
	int id;
	int candy;
};

int main() {
	queue<p> q;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p per;
		per.id = i;
		cin >> per.candy;
		q.push(per);
	}
	while (true) {
		p per = q.front();
		q.pop();
		if (q.size() == 0) {
			cout << per.id;
			break;
		}
		if ((per.id) % m == 0) {
			if (per.candy > 0) {
				per.candy--;
				q.push(per);
			}
		} else {
			q.push(per);
		}
		if (q.size() == 1) {
			p p2 = q.front();
			cout << p2.id;
			break;
		}
	}
	return 0;
}