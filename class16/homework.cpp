#include <iostream>
#include <cstring>
using namespace std;
bool vis[101];
int pic_map[101][101];
int n;

void dfs(int x) {
	vis[x] = true;
	cout << x << " ";
	for (int i = 1; i <= n; i++) {
		if (pic_map[x][i] == 0 || vis[i]) {
			continue;
		}
		dfs(i);
	}
}

int main() {
	int m;
	memset(pic_map, 0, sizeof(pic_map));
	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	int x2;
	bool flag = true;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (flag) {
			flag = false;
			x2 = x;
		}
		pic_map[x][y] = 1;
		pic_map[y][x] = 1;
	}
	dfs(x2);
	return 0;
}