#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int ma[n][m];
    int mb[n][m];
    int ans[n][m];
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin>>ma[i][j];
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin>>mb[i][j];
            ans[i][j] = (mb[i][j] + ma[i][j]);
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}