/*
  1.输入数组matrix,ans
  2.四周元素相加/4 四舍五入
  3.输出ans
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	int m, n;
	stringstream ss;
	int matrix[m][n], ans[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			if (i == 0 || i == (m - 1) || j == 0 || j == (n - 1)) {
				ans[i][j] = matrix[i][j];
			} else {
				ans[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] != -1) {
				continue;
			}
			ss.clear();
			ss.str("");
			//ans[i-1][j] + ans[i+1][j]+ans[i][j - 1]+ans[i][j+1]
			double tmp = ans[i - 1][j] + ans[i + 1][j] + ans[i][j - 1] + ans[i][j + 1];
			ss<<tmp;
			string tmp2;
			ss>>tmp2;
			
		}
	}
	return 0;
}
