#include <iostream>
using namespace std;
int sum[125][125];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			int tmp;
			cin>>tmp;
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + tmp;
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++) {//x1
		for(int j = 1;j<=n;j++) {//y1
			for(int k = i;k<=n;k++) {//x2
				for(int z = j;z<=n;z++) {//y2
					ans = max(ans,sum[k][z] - sum[k][j - 1] - sum[i - 1][z] + sum[i - 1][j - 1]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
