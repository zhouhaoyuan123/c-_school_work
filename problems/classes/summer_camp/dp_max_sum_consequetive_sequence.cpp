#include <iostream>
using namespace std;
long long dp[1000005];
long long num[1000005];
long long ans;

int main() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>num[i];
    }
    dp[1] = num[1];
   // ans = num[1] + num[1];
    long long ans2 = num[1];
    for(int i = 2;i<=n;i++) {
        dp[i] = max(dp[i - 1] + num[i],num[i]);
        //ans2 = max(ans2,ans);
        //cout << ans2 << " ";
        ans = 0;
        for(int j = 1;j<i;j++) {
            if(j == 1) {
                ans = max(ans,num[j]);
            }
            else ans = max(ans,num[j] + dp[j]);
        }
        ans2 = max(ans2,ans);
    }
    cout << ans2<<endl;
    return 0;
}