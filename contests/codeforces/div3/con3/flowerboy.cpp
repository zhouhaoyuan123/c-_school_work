#include <iostream>
#include <cstring>
using namespace std;
int a[200005],b[200005];
int ans1[200005],ans2[200005];

int main() {
	int t;
	cin>>t;
	while(t --) {
		int n,m;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(ans1,0,sizeof(ans1));
		memset(ans2,0,sizeof(ans2));
		for(int i = 1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i = 1;i<=m;i++) {
			cin>>b[i];
		} 
		int cnt = 1;
		for(int i = 1;i<=n;i++) {
			if(cnt > m) break;
			if(a[i] >= b[cnt]) {
				ans1[cnt] = i;
				cnt ++;
			}
		}
		cnt = m;
		for(int j = n;j>=1;j--) {
			if(cnt < 1) break;
			if(a[j] >= b[cnt]) {
				ans2[cnt] = j;
				cnt --;
			}
		}
		int ans = 0x3f3f3f3f;
		if(ans1[m] != 0) {
			cout << 0 << endl;
			continue;
		}
		ans2[m + 1] = n + 1;
		for(int i = 1;i<=m;i++) {
			if(ans1[i - 1] < ans2[i + 1]) {
				if((i - 1 == 0 || (i - 1 > 0 && ans1[i - 1] != 0)) && (i + 1 == n + 1 || (i + 1 <= n && ans2[i + 1] != 0)))
					ans = min(ans,b[i]);
			}
		}
		if(ans < 0x3f3f3f3f) {
			cout << ans << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}
