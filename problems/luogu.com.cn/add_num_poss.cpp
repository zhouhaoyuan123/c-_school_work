#include <bits/stdc++.h>
using namespace std;
int dp[1003],sum[1003];

int main() {
    int n;
    cin>>n;
    dp[n] = 1;
    fill(sum + (n / 2 + 1),sum+1+n,1);
    for(int i = n / 2;i>=1;i--) {
        if(i * 2 > n) {
            sum[i] = sum[i + 1];
            continue;
        }
        dp[i] = sum[i * 2];
        sum[i] = sum[i + 1] + dp[i];
        //cout << sum[i]<<" ";
    }    
    cout << sum[1];
    return 0;
}