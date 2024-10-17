#include <iostream>
#include <queue>
using namespace std;
int maze[35][35];
bool vis[35][35];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n;

void bfs(int x,int y) {
    queue<pair<int,int> > q;
    q.push({x,y});
    vis[x][y] = 1;
    maze[x][y] = 2;
    while(!q.empty()) {
        int x = q.front() . first , y = q.front() . second;
        q.pop();
        for(int i = 0;i<4;i++) {
            int nx = x + dir[i][0],ny = y + dir[i][1];
            if(0 <= nx && nx <= n + 1 && 0 <= ny && ny <= n + 1 && !vis[nx][ny] && maze[nx][ny] == 0) {
                vis[nx][ny] = 1;
                maze[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            cin>>maze[i][j];
        }
    }
    bfs(0,0);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(maze[i][j] == 2) {
                cout << 0 << " ";
            }
            else if(maze[i][j] == 1) {
                cout << 1 << " ";
            }
            else {
                cout << 2 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}