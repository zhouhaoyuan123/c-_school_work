#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long x[500005];
bool vis[500005];
priority_queue<pair<long long,int> > q;

int main() {
	int N,M;
	cin>>N>>M;
	if(M >= N) {
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1;i<=N;i++) {
		cin>>x[i];
	}
	sort(x + 1,x + 1 + N);
	for(int i = 1;i<N;i++) {
		q.push({x[i + 1] - x[i],i});
	}
	long long ans = 0;
	for(int i = 1;i<M;i++) {
		auto cur = q.top();
		q.pop();
		ans += cur.first;
	}
	cout << x[N] - x[1] - ans << endl;
	return 0;
}
