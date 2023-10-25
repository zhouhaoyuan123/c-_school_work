#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int pic_map[n + 1][n + 1];
	memset(pic_map, 0, sizeof(pic_map));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		pic_map[x][y] = 1;
		pic_map[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (pic_map[i][j] == 0) {
				//cout << "INF" << " ";
				continue;
			}
			cout << i << " " << j;
		}
		cout << endl;
	}

	return 0;
}