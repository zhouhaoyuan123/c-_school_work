#include <iostream>
#include <cmath>

using namespace std;
int num[1005][1005];
int dp[1005][1005];

int main() {
    int r;
    cin>>r;
    for(int i = 1;i<=r;i++) {
        for(int j = 1;j<=i;j++) {
            cin>>num[i][j];
        }
    }
    for(int i = 1;i<=r;i++) {
        for(int j = 1;j<=i;j++) {
            dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j]) + num[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i<=r;i++) {
        ans = max(ans,dp[r][i]);
    }
    cout << ans;
    return 0;
}