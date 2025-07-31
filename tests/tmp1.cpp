#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool maze[105][105];
bool vis[105][105];
bool a[55][55],b[55][55];
queue<pair<int,int> > q;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int bfs(int n,int m,int x,int y) {
	while(!q.empty()) q.pop();
	q.push({x,y});
	vis[x][y] = 1;
	int ans = 0;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		ans ++;
		for(int i = 0;i<4;i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny] && maze[nx][ny]) {
				vis[nx][ny] = 1;
				q.push({nx,ny});
			}
		}
	}
	return ans;
}
int calc(int n,int x,int y) {
	memset(vis,0,sizeof(vis));
	memset(maze,0,sizeof(maze));
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			maze[i][j] = a[i][j];
			maze[i + x - 1][j + y - 1] = b[i][j];
		}
	}
	int ans = 0;
	for(int i = 1;i<=n + x - 1;i++) {
		for(int j = 1;j<=n + y - 1;j++) {
			if(!vis[i][j]) {
				ans = max(bfs(n + x - 1,n + y - 1,i,j),ans);
			}
		}
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>b[i][j];
		}
	}
	
	return 0;
}
