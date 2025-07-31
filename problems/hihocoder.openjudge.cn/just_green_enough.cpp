#include <iostream>
using namespace std;
int num[505][505];
int cnt100[505][505];
int cntsml100[505][505];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cin>>num[i][j];
			cnt100[i][j] = cnt100[i - 1][j];
			cntsml100[i][j] = cntsml100[i - 1][j];
			if(num[i][j] == 100) {
				cnt100[i][j] ++;
			}
			if(num[i][j] < 100) {
				cntsml100[i][j] ++;
			}
		}
	}
	long long ans = 0;
	for(int s = 1;s <= n;s ++) {
		for(int t = s;t <= n;t ++) {
			int last100 = 0,lastsml100 = 0;
			for(int j = 1;j<=n;j++) {
				if(cnt100[t][j] - cnt100[s - 1][j] > 0) last100 = j;
				if(cntsml100[t][j] - cntsml100[s - 1][j] > 0) lastsml100 = j;
				if(last100 > lastsml100) ans += (last100 - lastsml100);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
