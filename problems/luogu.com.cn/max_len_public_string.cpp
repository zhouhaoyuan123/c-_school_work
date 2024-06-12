#include <iostream>
using namespace std;
int dict[100005][2];
int p1[100005];
int p2[100005];
int dp[100005],dp2[100005];

int main() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>p1[i];
        dict[p1[i]][0] = i;
    }
    for(int i = 1;i<=n;i++) {
        cin>>p2[i];
        dict[p2[i]][1] = i;
    }
    for(int i = 1;i<=n;i++) {
        if(dict[p2[i]][0] <= i)
            dp[i] = max(dp[i - 1],dp[dict[p2[i]][0] - 1] + 1);
        else
            dp[i] = dp[i - 1];
    }
    for(int i = 1;i<=n;i++) {
        if(dict[p1[i]][1] <= i)
            dp2[i] = max(dp2[i - 1],dp2[dict[p1[i]][1] - 1] + 1);
        else
            dp2[i] = dp2[i - 1];
    }
    cout << max(dp[n],dp2[n]);
    return 0;
}