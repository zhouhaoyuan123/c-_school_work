#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
long long dp[100005][105];

int main() {
    memset(dp,0x3f,sizeof(dp));
    int n;
    cin>>n;
    dp[1][1] = 1;
    long long ans = 0x3f3f3f3f;
    //cout << pow(n,1.0 / 4) << endl;
    for(int i = 0;i<=pow(n,1.0 / 4);i++) {
        dp[0][i] = 0;
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=pow(n,1.0 / 4);j++) {
            if(i == 1 && j == 1) {
                continue;
            }
            if(i >= j * j * j * j) {
                dp[i][j] = min(dp[i][j - 1] , dp[i - j * j * j * j][j] + 1);
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
            if(i == n) ans = min(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}