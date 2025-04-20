#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<long long,long long> , vector<pair<long long,long long> > , greater<pair<long long,long long> > > q;

int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++) {
		long long x;
		cin>>x;
		q.push({x,1});
	}
	while((n - 1) % (k - 1) != 0) {
		q.push({0,1});
		n ++;
	}
	long long ans = 0;
	while(q.size() >= k) {
		long long tmp = 0,maxn = 0;
		for(int i = 1;i<=k;i++) {
			long long w = q.top().first;
			long long step = q.top().second;
			maxn = max(maxn,step);
			q.pop();
			tmp += w;
		}
		ans += tmp;//wpl
		q.push({tmp,maxn + 1});
	}
	cout << ans << endl << q.top().second - 1 << endl;
	return 0;
}
