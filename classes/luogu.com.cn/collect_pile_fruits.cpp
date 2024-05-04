#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin>>n;
	priority_queue<long long,vector<long long>,greater<long long> > q;
	for(int i = 1;i<=n;i++) {
		int tmp;
		cin>>tmp;
		q.push(tmp);
	}
	long long ans = 0;
	while(q.size() > 1) {
		long long a = q.top();
		q.pop();
		long long b = q.top();
		q.pop();
		q.push(a+b);
		ans = ans + a + b;
	}
	cout << ans;
	return 0;
}
