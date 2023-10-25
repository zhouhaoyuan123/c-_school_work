#include <iostream>
using namespace std;
int G[101][101];

int vis[101] = {0};
int n;
void DFS(int s, int fill) {
	if (vis[s] > 0) {
		return;
	}
	vis[s] = fill;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0 && G[s][i]) {
			//vis[i] = fill;
			DFS(i, fill);
		}
	}
}

int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		G[y][x] = 1;
		G[x][y] = 1;
	}
	for (int i = n; i >= 1; i--) {
		DFS(i, i);
	}
	for (int i = 1; i <= n; i++) {
		cout << vis[i] << " ";
	}
	return 0;
}