#include <iostream>
using namespace std;
bool vis[110000005];
int primes[110000005];
int cnt;

int main() {
    ios::sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    for(int i = 2;i<=n;i++) {
        if(!vis[i]) {
            primes[++cnt] = i;
        }
        for(int j = i,k = 1;j * primes[k]<=n && k <= cnt;k++) {
            vis[j * primes[k]] = 1;
            if(j % primes[k] == 0) {
                break;
            }
        }
    }
    for(int i = 1;i<=q;i++) {
        int k;
        cin>>k;
        cout << primes[k]<<endl;
    }
    return 0;
}