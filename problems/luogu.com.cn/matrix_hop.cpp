#include <iostream>
using namespace std;
int num[35][35];
int dp[35][35];

int main() {
    int n,m;
    cin>>n>>m;
    dp[1][1] = 1;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(i == 1 && j == 1) continue;
            if(i % 2 == 0 && j % 2 == 0) {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m];
    return 0;
}