#include <iostream>
using namespace std;
int num[125][125];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>num[i][j];
			num[i][j] = num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1] + num[i][j];
		}
	}
	int ans = -1e7;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			for(int k = i;k<=n;k++) {
				for(int x = j;x<=n;x++) {
					ans = max(ans,num[k][x] - num[k - i][x] - num[k][x - j] + num[k - i][x - j]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
