#include <iostream>
using namespace std;
bool vis[100000005];
int primes[100000005];

int main() {
    int n;
    cin>>n;
    int cnt = 0;
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
    cout << cnt<<endl;
    return 0;
}