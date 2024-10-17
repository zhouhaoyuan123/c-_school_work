#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <iomanip>
using namespace std;

//string maze[1005];
long long ans[1005][1005];
bool vis[1005][1005];
int dir[8][2] = {{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};

int main() {
    memset(ans,0x3f,sizeof(ans));
    int n,m;
    cin>>n>>m;
    int sx,sy;
    cin>>sx>>sy;
    queue<pair<int,pair<int,int> > > q;
    q.push({sx,{sy,0}});
    vis[sx][sy] = 1;
    ans[sx][sy] = 0;
    while(!q.empty()) {
        int x = q.front() . first;
        int y = q.front() . second . first;
        int step = q.front() . second . second;
        q.pop();
        for(int i = 0;i<8;i++) {
            int nx = x + dir[i][0],ny = y + dir[i][1];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny]) {
                q.push({nx,{ny,step + 1}});
                vis[nx][ny] = 1;
                ans[nx][ny] = min(ans[nx][ny],1ll * step + 1);
            }
        }
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(ans[i][j] >= 0x3f3f3f3f) {
                cout << -1 <<" ";
            }
            else {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}