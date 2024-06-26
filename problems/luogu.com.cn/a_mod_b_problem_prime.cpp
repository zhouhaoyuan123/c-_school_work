#include <iostream>
using namespace std;
bool vis[1100005];
int primes[1100005];
int cnt;

int main() {
    int n,m;
    cin>>n>>m;
    vis[0] = 1;
    vis[1] = 1;
    for(int i = 2;i<=m;i++) {
        if(!vis[i]) {
            //primes[++cnt] = i;
            for(int j = i * 2;j<=m;j += i) {
                vis[j] = 1;
            }
        }
    }
    for(int i = 1;i<=m;i++) {
        if(!vis[i]) {
            primes[i] = primes[i - 1] + 1;
        }
        else {
            primes[i] = primes[i - 1];
        }
    }
    for(int i = 1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        if(x >= 1 && y <= m && x <= y) {
            cout << primes[y] - primes[x - 1]<<endl;
        }
        else {
            cout << "Crossing the line"<<endl;
        }
    }
    return 0;
}