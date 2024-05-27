#include <iostream>
using namespace std;
long long sum[200005],sum2[200005];
int w[200005],v[200005],l[200005],r[200005];
int n,m;
long long s;
long long judge(int lim) {
	sum[0] = 0,sum2[0] = 0;
	for(int i = 1;i<=n;i++) {
		sum[i] = 0;
		sum2[i] = 0;
		sum[i] = sum[i - 1];
		sum2[i] = sum2[i - 1];
		if(w[i] >= lim) {
			sum[i] ++;
			sum2[i] += 1ll * v[i];
		}
	}
	long long ans = 0;
	for(int i = 1;i<=m;i++) {
		ans += 1ll * (sum[r[i]] - sum[l[i] - 1]) * (sum2[r[i]] - sum2[l[i] - 1]);
	}
	return ans;
}
int main() {
	cin>>n>>m>>s;
	for(int i = 1;i<=n;i++) {
		cin>>w[i]>>v[i];
	}
	for(int i = 1;i<=m;i++) {
		cin>>l[i]>>r[i];
	}
	int l = 1,r = 1e6;
	while(l + 1 < r) {
		int mid = (l + r) / 2;
		long long tmp = judge(mid) - s;
		if(tmp > 0) {
			l = mid;
//			ans = min(ans,abs(tmp));
		}
		else if(tmp < 0) {
			r = mid;
			//ans = min(ans,abs(tmp));
//			if(ans == 0) {
//				break;
//			}
		}
		else {
			cout << 0;
			return 0;
		}
	}
	long long sum1 = abs(judge(l) - s);
	long long sum2 = abs(judge(r) - s);
	cout << min(sum1,sum2);
	return 0;
}
