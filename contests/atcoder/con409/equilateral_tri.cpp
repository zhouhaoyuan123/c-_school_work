#include <iostream>
using namespace std;
int num[300005];
int dis[300005];

int main() {
	int n,L;
	cin>>n>>L;
	int cur = 0;
	num[cur] ++;
	for(int i = 1;i<n;i++) {
		cin>>dis[i];
		num[(cur + dis[i]) % L] ++;
		cur = (cur + dis[i]) % L;
	}
	long long ans = 0;
	if(L % 3) {
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0;i<L;i++) {
		if(((i + L / 3) % L + L / 3) % L > i && (i + L / 3) % L > i) {
			if(num[i] > 0 && num[(i + L / 3) % L] > 0 && num[((i + L / 3) % L + L / 3) % L] > 0) {
				ans += 1ll * num[i] * num[((i + L / 3) % L + L / 3) % L] * num[(i + L / 3) % L];
			}	
		}
	}
	cout << ans << endl;
	return 0;
}
