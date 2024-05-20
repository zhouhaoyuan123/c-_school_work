#include <iostream>
#include <cstring>
using namespace std;
int n,m;
long long r[1000005],d[1000005],s[1000005],t[1000005];;
long long dis[1000005];
bool judge(int x) {
	memset(dis,0,sizeof(dis));
	long long cur = 0;
	for(int i = 1;i<=x;i++) {
		dis[s[i]] += d[i];
		dis[t[i] + 1] -= d[i];
	}
	for(int i = 1;i<=n;i++) {
		cur += 1ll * dis[i];
		if(cur > r[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>r[i];
		dis[i] = r[i] - r[i - 1];
	}
	for(int i = 1;i<=m;i++) {
		cin>>d[i]>>s[i]>>t[i];
	}
	if(judge(m)) {cout << 0;return 0;}
	int l = 1,r = m;
	while(l<r) {
		int mid = (l + r) / 2;
		if(judge(mid)) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	cout << -1<<endl<<l;
	return 0;
}
