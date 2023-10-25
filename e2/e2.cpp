#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int ma[n][m];
	int mb[m][k];
	int mc[n][k];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ma[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> mb[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int tmp = 0;
			for (int x = 0; x < m; x++) {
				tmp += (ma[i][x] * mb[x][j]);
			}
			mc[i][j] = tmp;
			cout << mc[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}