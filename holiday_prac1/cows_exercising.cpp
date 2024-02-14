#include <iostream>
using namespace std;
int rankings[15][25];

int main() {
	int n,k;
	cin>>k>>n;
	for(int i = 1;i<=k;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>rankings[i][j];
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(j == i) continue;
			bool fflag = true;
			for(int z = 1;z<=k;z++) {
				bool flag = false;
				for(int h = 1;h<=n;h++) {
					if(rankings[z][h] == j && !flag) {
						//cout << "exit : "<<i <<" "<<j<<" "<<z<<" "<<h;
						break;
					}
					if(rankings[z][h] == i) {
						flag = true;
					}
				}
				if(!(fflag && flag)) {
					fflag = false;
					break;
				}
			}
			if(fflag) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
