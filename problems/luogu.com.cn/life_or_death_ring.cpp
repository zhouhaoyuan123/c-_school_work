#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	queue<int> q;
	for(int i = 1;i<=n;i++) {
		q.push(i);
	}
	int cnt = 1;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		if(m == cnt) {
			cnt = 1;
			cout << t<<" ";
			continue;
		}
		cnt++;
		q.push(t);
	}
	return 0;
}
