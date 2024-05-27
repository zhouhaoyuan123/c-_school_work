#include <iostream>
using namespace std;
int matrix[1005][1005];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j = x1;j<=x2;j++) {
			matrix[j][y1] += 1;
			matrix[j][y2 + 1] -= 1;
		}
	}
	for(int i = 1;i<=n;i++) {
		int cnt = 0;
		for(int j = 1;j<=n;j++) {
			cout << cnt + matrix[i][j]<<" ";
			cnt += matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}
