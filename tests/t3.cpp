#include <iostream>
using namespace std;
bool vis[1000005];
int primes[1000005];
int max_prime_factor[1000005];
int cnt = 0;

int main() {
    int n,b;
    cin>>n>>b;
    for(int i = 2;i<=n;i++) {
        if(!vis[i]) {
            primes[++cnt] = i;
            max_prime_factor[i] = i;
        }
        for(int j = 1;j<=cnt && primes[j] * i <= n;j++) {
            vis[primes[j] * i] = 1;
            max_prime_factor[primes[j] * i] = max(max_prime_factor[primes[j] * i],max(max_prime_factor[i],primes[j]));
            if(i % primes[j] == 0) {
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 2;i<=n;i++) {
        if(max_prime_factor[i] <= b) {
            ans ++;
        }
    }
    cout << ans + 1;
    return 0;
}