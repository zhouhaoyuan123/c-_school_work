#include <iostream>
using namespace std;
int w[1005],v[1005];
int dp[1005][1005];

int main() {
    int N,W;
    cin>>N>>W;
    for(int i = 1;i<=N;i++) {
        cin>>w[i]>>v[i];
    }
    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=W;j++) {
            if(j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j],dp[i][j - w[i]] + v[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][W];
    return 0;
}