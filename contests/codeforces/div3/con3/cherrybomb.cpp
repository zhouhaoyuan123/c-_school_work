#include <iostream>
#include <cstring>
using namespace std;
long long a[200005],b[200005];

int main() {
	int t;
	cin>>t;
	while(t --) {
		long long n,k;
		cin>>n>>k;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		long long minn = k + 1,maxn = 0;
		for(int i = 1;i<=n;i++) {
			cin>>a[i];
			minn = min(a[i],minn);
			maxn = max(a[i],maxn);
		}
		long long sum = -1;
		bool flag = 0;
		for(int i = 1;i<=n;i++) {
			cin>>b[i];
			if(b[i] != -1) {
				int tmp = a[i] + b[i];
				if(sum != -1 && tmp != sum) {
					flag = 1;
				}
				else if(sum == -1) {
					sum = tmp;
				}
			}
			if(sum != -1 && (a[i] + k < sum || a[i] > sum)) {
				flag = 1;
			}
		}
		if(flag) {
			cout << 0 << endl;
			continue;
		}
		if(sum != -1) {
			cout << 1 << endl;
			continue;
		}
		cout << max(minn + k - maxn + 1,1ll * 0) << endl;
	}
	return 0;
}
