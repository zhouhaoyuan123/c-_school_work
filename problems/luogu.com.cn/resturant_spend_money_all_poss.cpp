#include <iostream>
using namespace std;
int c[105];
int dp[105][10005];

int main() {
    int M,N;
    cin>>N>>M;
    for(int i = 1;i<=N;i++) {
        cin>>c[i];
    }
    dp[0][0] = 1;
    for(int i = 1;i<=N;i++) {
        dp[i][0] = 1;
    }
    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=M;j++) {
            if(j >= c[i]) {
                dp[i][j] = dp[i - 1][j - c[i]] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][M];
    return 0;
}