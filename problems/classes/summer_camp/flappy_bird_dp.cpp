#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[10005][2];
bool vis[10005][1005];
int dp[10005][1005];
int target[10005];
int ans[10005];

int main() {
    memset(ans,0x3f,sizeof(ans));
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++) {
        cin>>num[i][1] >> num[i][0];
    }
    int cnt = 0;
    for(int i = 1;i<=k;i++) {
        int p,x,y;
        cin>>p>>x>>y;
        target[++cnt] = p;
        for(int j = m ;j>=y;j--) {
            dp[p][j] = 0x3f3f3f3f;
        }
        for(int j = x;j>=1;j--) {
            dp[p][i] = 0x3f3f3f3f;
        }
    }
    sort(target+1,target+1+cnt);
    for(int i = 2;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(j + num[i - 1][0] > m && j - num[i - 1][1] <= 1) {
                dp[i][j] = 0x3f3f3f3f;
            }
            if(dp[i][j] == 0x3f3f3f3f || (dp[i][j - num[i - 1][1]] == 0x3f3f3f3f && dp[i - 1][j - num[i - 1][1]] == 0x3f3f3f3f && dp[i - 1][j + num[i - 1][0]] == 0x3f3f3f3f)) {
                continue;
            }
            if(j + num[i - 1][0] > m) {
                dp[i][j] = min(dp[i][j - num[i - 1][1]] + 1 , dp[i - 1][j - num[i -1][1]] + 1);
            }
            else if (j - num[i - 1][1] <= 1) {
                dp[i][j] = dp[i - 1][j + num[i - 1][0]];
            }
            else
                dp[i][j] = min(dp[i - 1][j + num[i - 1][0]],min(dp[i][j - num[i - 1][1]] + 1,dp[i - 1][j - num[i - 1][1]] + 1));
            ans[i] = min(ans[i],dp[i][j]);
            cout << dp[i][j]<<" ";
        }
        cout << endl;
    }
    if(ans[n] <= 0x3f3f3f3f) {
        cout << 1 << endl << ans[n] << endl;
    }
    else {
        int i;
        for(i = 1;i<=n;i++) {if(ans[i] >= 0x3f3f3f3f) break;}
        cout << 0 << endl << i - 1<<endl;
    }
    return 0;
}