#include <iostream>
using namespace std;
bool vis[5005];
int factor[5005];

int main() {
    int m,n;
    cin>>m>>n;
    for(int i = 2;i<=max(n,m);i++) {
        if(!vis[i]) {
            factor[i] = i;
            for(int j = i * 2;j<=max(n,m);j+=i) {
                vis[j] = 1;
                factor[j] = max(factor[j],i);
            }
        }
    }
    for(int i = min(n,m);i<=max(n,m);i++) {
        cout << factor[i];
        if(i != max(n,m)) {
            cout << ",";
        }
    }
    cout << endl;
    return 0;
}