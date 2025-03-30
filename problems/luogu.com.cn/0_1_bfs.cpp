#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1005;
char G[MAXN][MAXN];
int vis[MAXN][MAXN], ans[MAXN*MAXN];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int n, m, cnt_id = 1;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = cnt_id;
	int cnt = 1;
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int d=0; d<4; ++d) {
			int nx = x + dir[d][0], ny = y + dir[d][1];
			if (nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && G[nx][ny]!=G[x][y]) {
				vis[nx][ny] = cnt_id;
				cnt++;
				q.push({nx, ny});
			}
		}
	}
	ans[cnt_id++] = cnt;
}

void preprocess() {
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!vis[i][j]) bfs(i, j);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> G[i];
	preprocess();
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << ans[vis[x-1][y-1]] << "\n"; // 坐标转换
	}
	return 0;
}
