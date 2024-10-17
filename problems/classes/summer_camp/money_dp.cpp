#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int num[105];
bool dp[25005];

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i<=n;i++) {
            cin>>num[i];
        }
        memset(dp,0,sizeof(dp));
        sort(num+1,num+1+n);
        int tmp = n;
        dp[0] = 1;
        for(int i = 1;i<=n;i++) {
            if(dp[num[i]]) {
                tmp --;
            }
            else {
                for(int j = num[i];j<=num[n];j++) {
                    dp[j] |= dp[j - num[i]];
                }
            }
        }
        cout << tmp << endl;
    }
    return 0;
}