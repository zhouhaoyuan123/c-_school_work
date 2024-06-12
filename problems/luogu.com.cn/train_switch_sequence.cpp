#include <iostream>
using namespace std;
long long dp[20];

int main() {
    int n;
    cin>>n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i<=n;i++) {
        for(int j = 1;j<=i;j++) {
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }
    cout << dp[n];
    return 0;
}