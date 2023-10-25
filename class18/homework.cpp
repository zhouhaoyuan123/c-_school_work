#include <iostream>
#include <iomanip>
using namespace std;
int n, m;
double G[101][101], dis[101], vis[101];
double sum = 1;
void djstrika(int s) {
	for (int i = 1; i <= n; i++) { //找到点集为空
		int x;
		double dism;
		x = dism = 1e6;
		for (int j = 1; j <= n; j++) { //找最优点
			if (dism > dis[j] && vis[j] == 0) {
				x = j;
				dism = dis[j];
			}
		}
		if (dism == 1e6) {
			break;
		}
		vis[x] = 1;//标记
		for (int j = 1; j <= n; j++) {
			if (G[x][j] != 1e6 && dism / (100 - G[x][j]) * 100 < dis[j]) { //更新其邻居
				dis[j] = dism / (100 - G[x][j]) * 100;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			G[i][j] = 1e6;
		}
		dis[i] = 1e6;
		vis[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		double z;
		cin >> x >> y >> z;
		G[x][y] = z;
		G[y][x] = z;
	}
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= n; i++) {
		if(G[y][i] == 1e6) {
			dis[i] = 1e6;
			continue;
		}
		dis[i] = 100 / (100 - G[y][i]) * 100;
	}
	djstrika(y);
	cout << fixed << setprecision(8) << dis[x];
	return 0;
}
