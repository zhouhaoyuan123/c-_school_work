#include <iostream>
using namespace std;
int l,n,m;
long long stones[50005];
bool judge(long long lim) {
	int cnt = 0;
	long long last_n = 0;
	for(int i = 1;i<=n+1;i++) {
		if(stones[i] - stones[last_n] >= lim) {
			last_n = i;
		} 
		else {
			cnt ++;
		}
	}
	return cnt <= m;
}

int main() {
	cin>>l>>n>>m;
	stones[n + 1] = l;
	for(int i = 1;i<=n;i++) {
		cin>>stones[i];
	}
	long long l = 1,r = 1e9 - 1;
	long long ans = 0;
	while(l <= r) {
		long long mid = (l + r) / 2;
		if(judge(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
