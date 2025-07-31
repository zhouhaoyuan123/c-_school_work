#include <iostream>
using namespace std;
int a[100005];
int b[100005];

int main() {
	int n,m;
	cin>>n>>m;
	int cnt1 = 1,cnt2 = 1;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=m;i++) cin>>b[i];
	int ans = 0;
	while(cnt1 <= n && cnt2 <= m) {
		if(a[cnt1] != b[cnt2]) {
			while(a[cnt1] != b[cnt2] && cnt1 <=n && cnt2 <= m) {
				if(a[cnt1] < b[cnt2]) {
					a[cnt1 + 1] += a[cnt1];
					cnt1 ++;
				}
				else {
					b[cnt2 + 1] += b[cnt2];
					cnt2 ++;
				}
				ans ++;
			}
		}
		else {
			cnt1 ++;
			cnt2 ++;
		}
	}
	cout << ans << endl;
	return 0;
}
