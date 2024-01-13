#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
int n,m;
int maze[1005][1005];
bool vis[1005][1005];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int maxn = 0;
set<int> kinds;
void dfs(int x,int y) {
	vis[x][y] = true;
	kinds.insert(maze[x][y]);
	if(maxn < kinds.size()) {
		maxn = kinds.size();
	}
	for(int i = 0;i<4;i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(0 <= tx && tx < n && 0<=ty && ty < m && maze[tx][ty] && !vis[tx][ty]) {
			dfs(tx,ty);
		}
	}
}

int main() {
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			cin>>maze[i][j];
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			if(! vis[i][j] && maze[i][j]) {
				kinds.clear();
				dfs(i,j);
			}
		}
	}
	cout << maxn;
	return 0;
}
