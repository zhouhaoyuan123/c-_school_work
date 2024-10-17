#include <iostream>
#include <algorithm>
using namespace std;
long long num[1005];
long long res[1005][1005];
int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i = 1;i<=n;i++) {
        cin>>num[i];
        res[i][i] = num[i];
    }
    for(int i = 1;i<=n;i++) {
        for(int j = i + 1;j<=n;j++) {
            res[i][j] = __gcd(num[j],res[i][j - 1]);
        }
    }
    for(int i = 1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        if(l != r) {
            cout << res[l][r]<<endl;
        }
        else {
            cout << num[l]<<endl;
        }
    }
    return 0;
}