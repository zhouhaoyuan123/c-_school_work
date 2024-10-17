#include <iostream>
using namespace std;
int num[105];
int dp[105],dp2[105];

int main() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>num[i];
    }
    for(int i = 1;i<=n;i++) {
        dp[i] = 1;
        for(int j = 1;j<i;j++) {
            if(num[j] < num[i])
                dp[i] = max(dp[j] + 1,dp[i]);
        }
    }
    for(int i = n;i>=1;i--) {
        dp2[i] = 1;
        //cout << i << " : ";
        for(int j = i + 1;j<=n;j++) {
            if(num[j] < num[i]) {
                dp2[i] = max(dp2[j] + 1,dp2[i]);
                //cout << dp2[i]<<" ";
            }
        }
        //cout << endl;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        ans = max(ans,dp[i] + dp2[i] - 1);
    }
    cout << n - ans;
    return 0;
}