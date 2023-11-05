#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[10001][10001];

int main() {
	string b;
	cin>>b;
	string a = b;
	sort(b.begin(),b.end());
	for(int i = 1;i<=a.size();i++) {
		for(int j = 1;j<=b.size();j++) {
			if(a[i - 1] != b[j - 1]) {
				dp[i][j]= max(dp[i - 1][j],dp[i][j - 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	cout << a.size() - dp[a.size()][b.size()];
	return 0;
}
