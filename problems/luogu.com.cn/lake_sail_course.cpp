#include <iostream>
using namespace std;
long long dp[1005];
const long long mod =  10007;

int main() {
    int n;
    cin>>n;
    dp[0] = 1;
    dp[1] = 1;
    //dp[2] = 2;
    for(int i = 2;i<=n;i++) {
        dp[i] += dp[i - 1];
        for(int j = 2;j<=i;j++) {
            //dp[i] += (dp[j - 1] * dp[i - j]);
            dp[i] += dp[j - 2] * dp[i - j];
            dp[i] %= mod;
        }
        dp[i] %= mod;
    }
    cout << dp[n];
    return 0;
}