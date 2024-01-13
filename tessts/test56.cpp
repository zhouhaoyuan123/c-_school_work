#include <iostream>
using namespace std;
int G[205][205][205];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>G[0][i][j];
			for(int z = 1;z<=n;z++) {
				G[z][i][j] = G[0][i][j];
			}	
		}
	}  
	for(int k = 1;k<n;k++) {
		for(int i = 1+k;i<=n;i++) {
			for(int j = 1+k;j<=n;j++) {
				for(int z = 1+k;z<=n;z++) {
					G[k][j][z] = min(G[k][j][i] + G[k][i][z],G[k][j][z]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i<n;i++) {
		for(int j = i+1;j<=n;j++) {
			for(int z = i + 1;z<=n;z++) {
				ans += G[i][j][z];
			}
		}
	}
	cout << ans;
	return 0;
}
