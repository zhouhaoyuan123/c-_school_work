#include <iostream>
#include <string>
#include <queue>
using namespace std;

string maze[1005];
bool vis[1005][1005];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>maze[i];
    }
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    queue<pair<int,pair<int,int> > > q;
    q.push({sx,{sy,0}});
    vis[sx][sy] = 1;
    while(!q.empty()) {
        int x = q.front() . first;
        int y = q.front() . second . first;
        int step = q.front() . second . second;
        q.pop();
        if(x == tx && y == ty) {
            cout << step <<endl;
            return 0;
        }
        for(int i = 0;i<4;i++) {
            int nx = x + dir[i][0],ny = y + dir[i][1];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= n && maze[nx][ny - 1] == '0' && !vis[nx][ny]) {
                q.push({nx,{ny,step + 1}});
                vis[nx][ny] = 1;
            }
        }
    }
    cout << -1<<endl;
    return 0;
}