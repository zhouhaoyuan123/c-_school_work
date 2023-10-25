#include <iostream>
#include <cstring>
using namespace std;

/*
  1 1 2 3
1 1 1 1 1
2 1 2 2 2
3 1 2 3 3
4 1 2 4 4
5 1 2 4 5
6 1 2 4 6
 */
int c[95];
int weight[6] = {1,2,3,5,10,20};

int main() {
	int t = 0,cnt = 0;
	for(int i = 0;i<=6;i++) {
		int si;
		cin>>si;
		cnt += si * weight[i];
		int p = 1;
		while(si >= p) {
			t++;
			c[t] = p * weight[i];
			si -= p;
			p *= 2;
		}
		if(si > 0) {
			t++;
			c[t] = si * weight[i];
		}
	}
	int dp[cnt + 2][t + 2];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=t;i++) {
		for(int j = 1;j<=cnt;j++) {
			if(dp[j - 1][i] < dp[j][i]) {
				continue;
			}
			dp[j][i] = dp[j - 1][i];
			if(j-c[t] >= 0 && (j - c[t] == 0 || dp[j - c[t]][i - 1] >= dp[j - c[t] - 1][i - 1])) {
				dp[j][i]++;
			}
			dp[j + 1][i] = dp[j][i];
			dp[j][i+1] = dp[j][i];
		}
	}
	cout << "Total="<< dp[cnt][t];
	return 0;
}
