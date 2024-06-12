#include <iostream>
using namespace std;
int num[10005][3];
int dp[10005];
int calc (int x,int y,int x1,int y1) {
    return abs(x1 - x) + abs(y - y1);
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        cin>>num[i][0] >> num[i][1] >> num[i][2];
    }
    int ans = 0;
    for(int i = 1;i<=m;i++) {
        dp[i] = 1;
        for(int j = 1;j<=m;j++) {
            if(j == i) continue;
            if(calc(num[i][1],num[i][2],num[j][1],num[j][2]) <= abs(num[i][0] - num[j][0])) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}