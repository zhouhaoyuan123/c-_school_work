#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool dp[500005];

int main() {
	int T;
	cin>>T;
	while(T --) {
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		string stable;
		cin>>stable;
		int cnt = (1<<n) - 1;
		dp[0] = 1;
		for(int i = 1;i<=cnt;i++) {
			if(stable[i - 1] == '1') continue;
			for(int j = 0;j<n;j++) {
				if(i & (1 << j)) dp[i] |= dp[i - (1 << j)];
			}
		}
		cout << ((dp[cnt]) ? "Yes" : "No") << "\n";
	}
	cout << endl;
	return 0;
}
