#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int n;
string maze[25];
bool vis[25][25];
int cnt[30];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool check[25][25][25][25];
void bfs(int x,int y,int z,int k,int tx,int ty) {
	queue<pair<int,int> > q;
	q.push({tx,ty});
	vis[tx][ty] = 1;
	char tmp = maze[tx][ty];
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		int curx = cur.first,cury = cur.second;
		vis[curx][cury] = 1;
		for(int i = 0;i<4;i++) {
			int nx = curx + dir[i][0],ny = cury + dir[i][1];
			if(x <= nx && nx <= z && y <= ny && ny <= k && !vis[nx][ny] && maze[nx][ny] == tmp) {
				q.push({nx,ny});
			}
		}
	}
}
bool calc(int x,int y,int z,int k) {
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	for(int i = x;i<=z;i++) {
		for(int j = y;j<=k;j++) {
			if(!vis[i][j]) {
				cnt[maze[i][j] - 'A'] ++;
				bfs(x,y,z,k,i,j);
			}
		}
	}
	int tmp = 0,minn = 1e9,maxn = 0;
	for(int i = 0;i<26;i++) {
		if(cnt[i]) {
			tmp ++;
			minn = min(cnt[i],minn);
			maxn = max(cnt[i],maxn);
		}
	}
	if(tmp == 2 && minn == 1 && maxn == 2) {
		return true;
	}
	return false;
}

int main() {
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>maze[i];
	}
	for(int i = 0;i<n;i++) 
		for(int j = 0;j<n;j++)			
			for(int k = i;k<n;k++)			
				for(int z = j;z<n;z++)			
					check[i][j][k][z] = calc(i,j,k,z);
	for(int i = 0;i<n;i++) 
		for(int j = 0;j<n;j++)			
			for(int k = i;k<n;k++)			
				for(int z = j;z<n;z++)	
					if(check[i][j][k][z])
						for(int a = 0;a<n;a++) 
							for(int b = 0;b<n;b++)			
								for(int c = k;c<n;c++)			
									for(int d = z;d<n;d++)
										if(!(a == i && b == j && c == k && d == z) && check[a][b][c][d] && check[i][j][k][z] && a <= i && b <= j && c >= k && d >= z) {
											check[i][j][k][z] = 0;
											break;
										}
	int ans = 0;
	for(int i = 0;i<n;i++) 
		for(int j = 0;j<n;j++)			
			for(int k = i;k<n;k++)			
				for(int z = j;z<n;z++)			
					if(check[i][j][k][z])
						ans ++;
	cout << ans << endl;
	return 0;
}
