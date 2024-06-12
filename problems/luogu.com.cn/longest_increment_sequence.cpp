#include <iostream>
using namespace std;
int dp[5005];
int num[5005];
int ans = 0;

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
                dp[i] = max(dp[i],dp[j] + 1);
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}