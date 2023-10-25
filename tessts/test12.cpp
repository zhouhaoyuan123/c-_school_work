#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	queue<int> park;
	queue<int> q;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	do {
		if (park.size() > n) {
			park.pop();
		}//make sure there are no more than n cars
		if (q.empty()) {
			break;
		}//last time
		int t = q.front();
		q.pop();
		park.push(t);
	} while (!q.empty());
	if (park.size() > n) {
		park.pop();
	}//make sure there are no more than n cars
	while (!park.empty()) {
		cout << park.front() << " ";
		park.pop();
	}
	return 0;
}