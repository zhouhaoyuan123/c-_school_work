#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dp[105][200005];
int owner[105][200005];
vector<int> dict[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T --) {
		memset(dp,0,sizeof(dp));
		memset(owner,0,sizeof(owner));
		int n,lim,q;
		cin>>n>>lim>>q;
		for(int i = 1;i<=n;i++) {
			dict[i].clear();
			int tmp;
			cin>>tmp;
			while(tmp --) {
				int x;
				cin>>x;
				dict[i].push_back(x);
			}
		}
		dp[0][1] = 1;
		for(int i = 1;i<=101;i++) {
			for(int j = 1;j<=n;j++) {
				int flag = 0;
				for(int k = 0;k<dict[j].size();k++) {
					if(owner[i - 1][dict[j][k]] == j) {
						if(k >= lim)
							flag -= min(dp[i - 1][dict[j][k - lim]],1);
						continue;
					}
					if(k - lim >= 0 && i == 1) break;
					if(k < lim) {
						flag += min(dp[i - 1][dict[j][k]],1);
					}
					else {
						flag += min(dp[i - 1][dict[j][k]],1);
						if(owner[i - 1][dict[j][k - lim]] != j)
							flag -= min(dp[i - 1][dict[j][k - lim]],1);
					}
					if(flag && k >= 1) {
						if(!(i == 1 && !dp[i - 1][dict[j][0]])) {
							dp[i][dict[j][k]] ++;
						}
					}
					if(dp[i][dict[j][k]] == 1) {
						owner[i][dict[j][k]] = j;
					}
					else if(dp[i][dict[j][k]] > 1) {
						owner[i][dict[j][k]] = 0;
					}
				}
			}
		}
		while(q --) {
			int r,c;
			cin>>r>>c;
			cout << min(dp[r][c],1) << endl;
		}
	}
	return 0;
}
