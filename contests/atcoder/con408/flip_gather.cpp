#include <iostream>
#include <cstring>
using namespace std;
int dp[200005][2];
string num;
int res[200005][2];

int main() {
	int t;
	cin>>t;
	while(t --) {
		memset(dp,0x3f,sizeof(dp));
		memset(res,0,sizeof(res));
		dp[0][0] = 0;
		dp[0][1] = 0;
		int n;
		cin>>n;
		cin>>num;
		int cnt = 0;
		int l = 0;
		for(int i = 0;i<n;i++) {
			if(num[i] == '0') {
				if(l != i) {
					res[++cnt][0] = l + 1;
					res[cnt][1] = i;
					l = i + 1;
				}
				else {
					l = i + 1;
				}
			}
		}
		if(l < n) {
			res[++cnt][0] = l + 1;
			res[cnt][1] = n;
		}
		int tmp = 0;
		for(int i = 1;i<=cnt;i++) {
			dp[i][0] = min(dp[i - 1][1],dp[i - 1][0]) + res[i][1] - res[i][0] + 1;
			dp[i][1] = min(dp[i - 1][1] + res[i][0] - res[i - 1][1] - 1,tmp);
			tmp += (res[i][1] - res[i][0] + 1);
		}
		cout << min(dp[cnt][0],dp[cnt][1]) << endl;
	}
	return 0;
}
