#include <iostream>
using namespace std;
int dp[65][65][32005];
int child[65][65];
int cnt[65];
int v[65],p[65];

int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++) {
        //int v,p,
        int q;
        cin>>v[i]>>p[i]>>q;
        if(q != 0) {
            child[q][++ cnt[q]] = i;
        } 
    }
    for(int i = 1;i<=m;i++)  {
        for(int j = 1;j<=cnt[i];j++) {
            for(int k = 1;k<=n;k++) {
                dp[i][0][k] = dp[i - 1][cnt[i - 1]][k];
                dp[i][j][k] = max(dp[i][j - 1][k],dp[i][j][k]);
            }
        }
    }
    return 0;
}