#include <iostream>
using namespace std;
long long cnt[100005],path[100005];
long long a[100005],b[100005],c[100005];
long long ans = 0;

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		cin>>path[i];
		if(i == 1) {
			continue;
		}
		cnt[min(path[i - 1],path[i]) + 1] += 1;
		cnt[max(path[i - 1],path[i]) + 1] -= 1;
		//cout << cnt[min(path[i - 1],path[i]) + 1] << " " << cnt[max(path[i - 1],path[i]) + 1]<<endl;
	}
	for(int i = 2;i<=n;i++) {
		cnt[i] = cnt[i - 1] + cnt[i];
	}
	for(int i = 2;i<=n;i++) {
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i = 2;i<=n;i++) {
		ans += min(1ll * a[i] * cnt[i],c[i] + 1ll * b[i] * cnt[i]);
	}
	cout << ans;
	return 0;
}
