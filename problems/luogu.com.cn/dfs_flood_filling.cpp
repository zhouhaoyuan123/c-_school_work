#include <iostream>
#include <string>
using namespace std;
int h,w;
string maze[1005];
bool sta[1005][1005];
int cnt = 0;
int dir[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
void dfs(int x,int y) {
    if(!(0 <= x && x < h && 0 <= y && y < w) || sta[x][y] || maze[x][y] != 'W') {
        return;
    }
    sta[x][y] = 1;
    for(int i = 0;i<8;i++) {
        dfs(x + dir[i][0],y + dir[i][1]);
    }
}

int main() {
    cin>>h>>w;
    for(int i = 0;i<h;i++) {
        cin>>maze[i];
    }
    for(int i = 0;i<h;i++) {
        for(int j = 0;j<w;j++) {
            if(maze[i][j] == 'W' && !sta[i][j]) {
                cnt ++;
                //sta[i][j] = 1;
                dfs(i,j);
            }
        }
    }
    cout << cnt;
    return 0;
}