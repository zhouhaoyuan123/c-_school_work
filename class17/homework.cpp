#include <iostream>
#include <vector>
using namespace std;
int G[101][101];
int n;
bool flag = false;

void DFS(int p, vector<int> v, int s, vector<int> vis) {
	//vis[p] = 1;
	v.push_back(p);
	if (s <= 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		//flag = true;
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		if (G[p][i]) {
			G[p][i] = 0;
			G[i][p] = 0;
			DFS(i, v, s - 1, vis);
			G[p][i] = 1;
			G[i][p] = 1;
		}
	}
}

int main() {
	int m;
	cin >> n >> m;
	vector<int> v;
	vector<int> vis(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		DFS(i, v, m, vis);
//		if (flag) {
//			return 0;
//		}
	}
	return 0;
}
