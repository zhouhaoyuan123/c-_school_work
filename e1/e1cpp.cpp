#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> n >> m;
	int matrix[n][m];
	int ans[m][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			ans[j][i] = matrix[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}