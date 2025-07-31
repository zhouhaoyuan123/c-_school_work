#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;

int main() {
	long long n;
	int m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		long long x,y;
		cin>>x>>y;
		q.push({x - y,x});
	}
	long long ans = 0;
	while(!q.empty()) {
		auto cur = q.top();
		q.pop();
		if(cur.second <= n) {
			ans += ((n - cur.second) / cur.first + 1);
			n = n - ((n - cur.second) / cur.first + 1) * cur.first;
		}
	}
	cout << ans << endl;
	return 0;
}
