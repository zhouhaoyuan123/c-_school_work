#include <iostream>
using namespace std;
long long a[105][105],b[105][105];

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<= m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i = 1;i<=m;i++) {
        for(int j = 1;j<=k;j++) {
            cin>>b[i][j];
        }
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=k;j++) {
            long long tmp = 0;
            for(int k = 1;k<=m;k++) {
                tmp += a[i][k] * b[k][j];
            }
            cout << tmp <<" ";
        }
        cout << endl;
    }
    return 0;
}