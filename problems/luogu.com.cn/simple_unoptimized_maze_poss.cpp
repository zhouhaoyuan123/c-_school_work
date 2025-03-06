#include <iostream>
using namespace std;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool vis[10][10];
int n,m,t;
int sx,sy,fx,fy;
int ans = 0;
void dfs(int x,int y) {
	if(vis[x][y]) return;
	if(x == fx && y == fy) {ans ++;return;}
	vis[x][y] = true;
	for(int i = 0;i<4;i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m) {
			dfs(nx,ny);
		}
	}
	vis[x][y] = false;
}
int main() {
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	for(int i = 1;i<=t;i++) {
		int x,y;
		cin>>x>>y;
		vis[x][y] = 1;
	}
	dfs(sx,sy);
	cout << ans << endl;
	return 0;
}
