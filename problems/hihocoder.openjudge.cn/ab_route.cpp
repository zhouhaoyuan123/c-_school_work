#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e3+10;
int n,m,k,dis[maxn][maxn][10];
bool vis[maxn][maxn][10];
string maze[maxn];
queue<pair<int,pair<int,pair<int,int> > > > q;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int calc() {
	vis[0][0][0] = 1;
	q.push({0,{0,{0,0}}});
	while(!q.empty()) {
		auto cur = q.front();
		//cout << cur.first << " " << cur.second.first << " " << cur.second.second.first << " " << cur.second.second.second << endl;
		q.pop();
		if(cur.first == n - 1 && cur.second.first == m - 1) {
			return cur.second.second.second;
		}
		for(int i = 0;i<4;i++) {
			int nx = cur.first + dir[i][0];
			int ny = cur.second.first + dir[i][1];
			int nz = (cur.second.second.first + 1) % k;
			if(0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny][nz]
			&&	((nz != 0 && maze[cur.first][cur.second.first] == maze[nx][ny]) || (nz == 0 && maze[nx][ny] != maze[cur.first][cur.second.first])) ) {
				vis[nx][ny][nz] = 1;
				dis[nx][ny][nz] = cur.second.second.second + 1;
				q.push({nx,{ny,{nz,cur.second.second.second + 1}}});
			}
		}
	}
	return -1;
}

int main() {
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++) cin>>maze[i];
	cout << calc() << endl;
	return 0;
}
