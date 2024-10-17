#include <iostream>
#include <queue>
using namespace std;
bool vis[505][505];
int ans[505][505];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    queue<pair<int,int> > q;
    for(int i = 1;i<=a;i++) {
        int x,y;
        cin>>x>>y;
        ans[x][y] = 0;
        vis[x][y] = 1;
        q.push({x,y});
    }
    while(!q.empty()) {
        int x = q.front() . first;
        int y = q.front() . second;
        int w = ans[x][y];
        q.pop();
        for(int i = 0;i<4;i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                ans[nx][ny] = w + 1;
                q.push({nx,ny});
            }
        }       
    }
    for(int i = 1;i<=b;i++) {
        int x,y;
        cin>>x>>y;
        cout << ans[x][y] << endl;
    }
    return 0;
}