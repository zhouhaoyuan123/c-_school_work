#include <iostream>
using namespace std;
long long ans[1000005];

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 2;i<=k;i++) {
        for(int j = i;j<=k ;j+=i) {
            if(j > min(n,m)) {
                break;
            }
            ans[j] ++;
        }
    }
    long long cnt = 0;
    for(int i = 1;i<=k;i++) {
        cnt += i * 1ll * (ans[i] + 1) * (ans[i] + 1);
    }
    cout << cnt << endl;
    return 0;
}