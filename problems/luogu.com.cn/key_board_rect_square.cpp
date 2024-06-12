#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    long long ans = 0,ans2 = 0;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            ans2 += 1ll * (n - i + 1) * (m - j + 1) - min(n- i + 1,m - j + 1);
            ans += 1ll * min(n- i + 1,m - j + 1);
        }
    }
    cout << ans<<" "<< ans2;
    return 0;
}