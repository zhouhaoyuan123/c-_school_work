#include <iostream>
using namespace std;
int h,w;
long long maze[25][25];
bool vis[25][25];
long long ans = 0;
void dfs(int x,int y,long long res) {
	if(x > h) {
		ans = max(ans,res);
		return;
	}
	if(y > w) return;
	int nx = 0,ny = 0;
	if(y == w) {
		nx = x + 1;
		ny = 1;
	}
	else {
		nx = x;
		ny = y + 1;
	}
	if(!vis[x][y]) dfs(nx,ny,res ^ maze[x][y]);
	else dfs(nx,ny,res);
	if(x + 1 <= h && !vis[x][y] && !vis[x + 1][y]) {vis[x + 1][y] = 1;vis[x][y] = 1;dfs(nx,ny,res);vis[x + 1][y] = 0;vis[x][y] = 0;}
	if(y + 1 <= w && !vis[x][y] && !vis[x][y + 1]) {vis[x][y + 1] = 1;vis[x][y] = 1;dfs(nx,ny,res);vis[x][y + 1] = 0;vis[x][y] = 0;}
}

int main() {
	cin>>h>>w;
	for(int i = 1;i<=h;i++) {
		for(int j = 1;j<=w;j++) {
			cin>>maze[i][j];
		}
	}
	dfs(1,1,0);
	cout << ans << endl;
	return 0;
}
