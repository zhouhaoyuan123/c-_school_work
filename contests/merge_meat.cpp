#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > q;

int main() {
	long long n,m;
	cin>>n>>m;
	long long tmp = 0;
	for(int i = 1;i<=n;i++) {
		long long x;
		cin>>x;
		tmp += x;
		q.push(x);
	}
	if(m - tmp > 0)
		q.push(m - tmp);
	long long ans = 0;
	while(q.size() > 1) {
		long long a = q.top();
		q.pop();
		long long b = q.top();
		q.pop();
		q.push(a + b);
		ans += a + b;
	}
	cout << ans << endl;
	return 0;
}
