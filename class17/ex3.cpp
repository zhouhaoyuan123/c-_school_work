#include <iostream>
using namespace std;

const inf = 1e6;
int G[101][101];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				G[k][x] = min(G[k][x], G[k][y] + G[y][x]);
			}
		}
	}
}
int n, m;

void init_program() {
	cin >> n >> m;
	int cnt = m;
	int x, y;
	cin >> x >> y;
	int z;
	cin >> z;
	cnt--;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x == i && y == j) {
				G[x][y] = z;
				if (cnt  > 0) {
					cin >> x >> y >> z;
					cnt--;
				}
			} else {
				G[i][j] = inf;
			}
		}
	}
}

int main() {
	init_program();
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (G[i][j] == inf) {
				cout << "INF ";
			} else {
				cout << G[i][j] << " ";
			}
		}
	}
}