#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

long long maze[1005][1005];
bool vis[1005][1005];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    int n;
    cin>>n;
    memset(maze,0x3f,sizeof(maze));
    for(int i = 1;i<=n;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        x ++,y ++;
        maze[x][y] = min(maze[x][y],1ll * t);
        for(int i = 0;i<4;i++) {
            if(x + dir[i][0] >= 1  && y + dir[i][1] >= 1)
                maze[x + dir[i][0]][y + dir[i][1]] = min(maze[x + dir[i][0]][y + dir[i][1]],1ll * t);
        }
    }
    int sx,sy,tx,ty;
    sx = 1,sy = 1;
    queue<pair<int,pair<int,int> > > q;
    if(maze[sx][sy] == 0) {
        cout << -1 << endl;
        return 0;
    }
    q.push({sx,{sy,0}});
    vis[sx][sy] = 1;
    while(!q.empty()) {
        int x = q.front() . first;
        int y = q.front() . second . first;
        int step = q.front() . second . second;
        q.pop();
        if(maze[x][y] >= 0x3f3f3f3f) {
            cout << step <<endl;
            return 0;
        }
        for(int i = 0;i<4;i++) {
            int nx = x + dir[i][0],ny = y + dir[i][1];
            if(1 <= nx && 1 <= ny && nx <= 400 && ny <= 400 && maze[nx][ny] > step + 1 && !vis[nx][ny]) {
                q.push({nx,{ny,step + 1}});
                vis[nx][ny] = 1;
            }
        }
    }
    cout << -1<<endl;
    return 0;
}