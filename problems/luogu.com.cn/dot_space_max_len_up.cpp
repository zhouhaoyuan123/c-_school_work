#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
pair<int,int> point[505];
long long dp[505];

int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        point[i].first = x;
        point[i].second = y;
    }
    sort(point+1,point+1+n);
    long long ans = 0;
    for(int i = 1;i<=n;i++) {
        dp[i] = 1;
        for(int j = 1;j<i;j++) {
            if((point[i].first - point[j].first == 1 && point[i].second == point[j].second) || (point[i].second - point[j].second == 1 && point[i].first == point[j].first)) 
                dp[i] = max(dp[j] + 1,dp[i]);
        }
        ans = max(ans,dp[i]);
    }
    cout << ans + k;
    return 0;
}