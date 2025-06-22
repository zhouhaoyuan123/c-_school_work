#include <iostream>
#include <cstring>
using namespace std;
int n,m;
bool vis[15][15];
int ans = 0;
int dir[8][2] = {{1,2},{-1,2},{-2,1},{-2,-1},{2,1},{2,-1},{1,-2},{-1,-2}};
void dfs(int x,int y,int cnt) {
	if(cnt == 0) {
		ans ++;
		return;
	}
	vis[x][y] = 1;
	for(int i = 0;i<8;i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny]) {
			//cout << nx << " " << ny << " " << cnt - 1 << endl;
			dfs(nx,ny,cnt - 1);
		}
	}
	vis[x][y] = 0;
}

int main() {
	int t;
	cin>>t;
	while(t --) {
		int x,y;
		cin>>n>>m>>x>>y;
		x ++,y ++;
		ans = 0;
		dfs(x,y,n * m - 1);
		cout << ans << endl;
	}
	return 0;
}
