#include <iostream>
using namespace std;
int r,c;
int maze[105][105],ans[105][105];
bool vis[105][105];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y) {
	vis[x][y] = true;
	int tmp = ans[x][y];
	for(int i = 0;i<4;i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(!(1 <= nx && nx <= r && 1 <= ny && ny <= c && maze[nx][ny] < maze[x][y])) {
			continue;
		}
		if(vis[nx][ny]) {
			tmp = max(tmp,ans[x][y] + ans[nx][ny]);
		}
		else {
			tmp = max(tmp,ans[x][y] + dfs(nx,ny));
		}
	}
	ans[x][y] = tmp;
	ans[x][y] ++;
	return ans[x][y];
}

int main() {
	cin>>r>>c;
	for(int i = 1;i<=r;i++) {
		for(int j = 1;j<=c;j++) {
			cin>>maze[i][j];
		}
	}
	int sum = 0;
	for(int i = 1;i<=r;i++) {
		for(int j = 1;j<=c;j++) {
			if(!vis[i][j]) {
				dfs(i,j);
			}
			sum = max(sum,ans[i][j]);
			//cout << sum << " ";
		}
		//cout << endl;
	}
	cout << sum << endl;
	return 0;
}
