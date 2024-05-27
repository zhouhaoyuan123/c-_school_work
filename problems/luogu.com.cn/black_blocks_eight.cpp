#include <iostream>
using namespace std;
int n;
int num[105][105];
int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool vis[105][105];
void dfs(int i,int j) {
    if(!(1<=i&& i <=n&&1<=j&&j<=n)) {
        return;
    }
    if(vis[i][j] || num[i][j] == 0) {
        return;
    }
    vis[i][j] = 1;
    for(int x = 0;x<8;x++) {
        dfs(i + dir[x][0],j + dir[x][1]);
    }
}
int main() {
    cin>>n;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            cin>>num[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(!vis[i][j] && num[i][j] == 1) {
                ans ++;
                dfs(i,j);
            }
        }
    }
    cout << ans;
    return 0;
}