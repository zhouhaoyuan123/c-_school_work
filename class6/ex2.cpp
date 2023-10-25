#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	for (int i = 1; i <= 5; i++) {
		q.push(i);
	}
	cout << q.size() << endl;
	cout << q.front() << endl << q.back() << endl;
	q.pop();
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	if (!q.empty()) {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}
	return 0;
}