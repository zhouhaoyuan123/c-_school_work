#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin>>n;
	queue<int> q;
	for(int i = 1;i<=n;i++) {
		q.push(i);
	}
	while(q.size() >= 2) {
		int fir = q.front();
		q.pop();
		cout << fir<<" ";
		int sec = q.front();
		q.pop();
		q.push(sec);
	}
	cout << q.front();
	return 0;
}
