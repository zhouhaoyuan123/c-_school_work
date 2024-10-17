#include <iostream>
#include <cstring>
using namespace std;
int vis[1000005];
long long primes[1000005];

int main() {
    long long L,R;
    cin>>L>>R;
    int cnt = 0;
    int ans = 0;
    for(int i = 2;1ll * L * i <= R;i++) {
        if(!vis[i]) {
            primes[++cnt] = i;
        }
        for(int j = i,k = 1;1ll * L * j * primes[k]<=R && k <= cnt;k++) {
            vis[j * primes[k]] = 1;
            if(j % primes[k] == 0) {
                break;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    for(long long i = L;i<=R;i++) {
        if(vis[i - L ] == 1) {
            primes[++cnt] = i;
            ans++;
        }
        else if(vis[i - L] == 0) {
            if(i < 2) continue;
            for(long long j = 2;j * j <= i; j++) {
                if(i % j) {
                    continue;
                }
            }
            primes[++cnt] = i;
            ans ++;
        }
        for(long long j = i,k = 1;1ll * j * primes[k]<=R && k <= cnt;k++) {
            vis[j * primes[k] - L] = 2;
            if(j % primes[k] == 0) {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}