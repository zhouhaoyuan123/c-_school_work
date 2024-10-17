#include <iostream>
#include <deque>

using namespace std;
long long num[100005];
long long dp[100005];
long long sum[100005];

int main() {
    int n,k;
    cin>>n>>k;
    deque<pair<int,long long> > q;
    for(int i = 1;i<=n;i++) {
        cin>>num[i];
        sum[i] = sum[i - 1] + num[i];
    }
    dp[1] = num[1];
    q.push_back({1,dp[0] - sum[1]});
    for(int i = 1;i<=n;i++) {
        dp[i] = dp[i - 1];
        // for(int j = i - 1;j>=max(1,i - k + 1);j--) {
        //     dp[i] = max(dp[i],dp[j] - sum[j] + sum[i]);
        // }
        while(q.size() > 0 && i - q.front().first > k) {
            q.pop_front();
        }
        dp[i] = max(dp[i - 1],sum[i] + dp[q.front().first - 2] - sum[q.front().first - 1]);
        while(q.size() > 0 && dp[q.front().first - 1] - sum[q.front().first - 1] <= dp[i - 1] - sum[i]) {
            q.pop_back();
        }
        q.push_back({i,dp[i - 2] - sum[i]});
        cout << dp[i] << " ";
    } 
    cout << dp[n] << endl;
    return 0;
}