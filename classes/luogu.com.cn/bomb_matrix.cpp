#include <iostream> 
using namespace std;
int num[5005][5005];
int sum[5005][5005];

int main() {
	int n,m;
	cin>>n>>m;
	int x1 = 0,y1 = 0;
	for(int i = 1;i<=n;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		num[x][y] += z;
		x1 = max(x1,x);
		y1 = max(y1,y);
	}
	for(int i = 1;i<=x1;i++) {
		for(int j = 1;j<=y1;j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num[i][j];
		}
	}
	int ans = 0;
	m -= 2;
	if(m == -1) {
		m = 1;
	}
	if(m == 0) {
		cout << 0;
		return 0;
	}
	for(int i = 1;i<=x1;i++) {
		for(int j = 1;j<=y1;j++) {
			int tmp = 0;
			if(i + m - 1 > x1 && j + m - 1 > y1) {
				tmp = sum[x1][y1] - sum[x1 - m][y1] - sum[x1][y1 - m] + sum[x1 - m][y1 - m];
			}
			else if(i + m - 1 > x1) {
				tmp = sum[x1][j + m - 1] - sum[x1 - m][j + m - 1] - sum[x1][j - 1] + sum[x1 - m][j - 1];
			}
			else if(j + m - 1 > y1) {
				tmp = sum[i + m - 1][y1] - sum[i - 1][y1] - sum[i+m - 1][y1 - m] + sum[i - 1][y1 - m];
			}
			else {
				tmp = sum[i + m - 1][j + m - 1] - sum[i - 1][j + m - 1] - sum[i+m - 1][j - 1] + sum[i - 1][j - 1];
			}
			ans = max(ans,tmp);
		}
	}
	cout << ans;
	return 0;
}
