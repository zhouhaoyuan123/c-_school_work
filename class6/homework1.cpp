#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << "Discarded cards : ";
	while (q.size() >= 2) {
		cout << q.front() << " ";
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << endl << "Remaining cards: " << q.front();
	return 0;
}