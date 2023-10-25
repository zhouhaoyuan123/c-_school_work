#include <iostream>
#include <queue>
using namespace std;
int G[101][101];

int vis[101] = {0};
queue<int> q;
int n;
void BFS(int s) {
	if (vis[s]) {
		return;
	}
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		cout << u << " ";
		q.pop();
		for (int v = 1; v <= n; v++) {
			if (G[u][v] != 0 && vis[v] == 0) {
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}
int main() {
	cin >> n;
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		BFS(i);
	}
	return 0;
}