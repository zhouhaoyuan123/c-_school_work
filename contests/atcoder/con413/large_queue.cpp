#include <iostream>
#include <queue>
using namespace std;
deque<pair<long long,long long> > q;

int main() {
	int Q;
	cin>>Q;
	while(Q --) {
		int op;
		cin>>op;
		if(op == 1) {
			int c,x;
			cin>>c>>x;
			q.push_back({c,x});
		}
		else {
			int k;
			cin>>k;
			long long ans = 0;
			while(k > 0 && !q.empty()) {
				auto cur = q.front();
				q.pop_front();
				if(k < cur.first) {
					q.push_front({cur.first - k,cur.second});
					ans += cur.second * 1ll * k;
					k = 0;
				}
				else {
					ans += cur.first * cur.second;
					k -= cur.first;
				}
			}
			cout << ans << "\n";
		}
	}
	cout << endl;
	return 0;
}
