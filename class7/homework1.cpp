#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, draw = 1; //层数,计算次数
	cin >> n;
	vector<int> v[n];//图形矩阵
	int spaces = n - 1;//空格次数
	for (int i = 0; i < n; i++) { //层循环
		for (int j = 0; j < spaces; j++) { //空格
			cout << " ";
		}
		for (int j = 0; j < draw; j++) {
			if (j == 0 || j == draw - 1) {
				v[i].push_back(1);
			} else {
				v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]); //矩阵操作
				/*
					1
				  1	   1->j -> j+1
				 1  2   1

				*/
			}
			cout << v[i][j] << " ";
		}
		draw++;
		spaces--;//更新数据
		cout << endl;
	}
	return 0;
}