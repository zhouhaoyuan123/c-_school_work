#include <iostream>
#include <cstring>
using namespace std;
int dp[50005];
int pi[105],ci[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T --) {
		memset(dp,0,sizeof(dp));
		memset(pi,0,sizeof(pi));
		memset(ci,0,sizeof(ci));
		int n,p,q;
		cin>>n>>p>>q;
		for(int i = 1;i<=n;i++) {
			cin>>pi[i]>>ci[i];
		}
		int ans = 0x3f3f3f3f;
		for(int i = 1;i<=n;i++) {
			for(int j = q;j>=1;j--) {
				if(j >= ci[i]) {
					dp[j] = max(dp[j] , dp[j - ci[i]] + pi[i]);
				}
				if(dp[j] >= p) {
					ans = min(ans,j);
				}
			}
		}
		if(ans < 0x3f3f3f3f) {
			cout << ans << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}
