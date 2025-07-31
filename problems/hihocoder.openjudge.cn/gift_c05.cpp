#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
vector<long long> shops[100005];
bool vis[100005];
bool judge(long long x) {
	memset(vis,0,sizeof(vis));
	bool cnt = 0;
	for(int i = 0;i<m;i++) {
		int tmp = 0;
		for(int j = 0;j<n;j++) {
			if(shops[i][j] >= x) {
				tmp ++;
				vis[j] = 1;
			}
		}
		if(tmp >= 2) {
			cnt = 1;
		}
	}
	for(int i = 0;i<n;i++) if(!vis[i]) return false;
	if(!cnt) {
		return false;
	}
	return true;
}

int main() {
	cin>>m>>n;
	for(int i = 0;i<m;i++) {
		for(int j = 0;j<n;j++) {
			long long x;
			cin>>x;
			shops[i].push_back(x);
		}
	}
	long long l = 1 , r = 1e9;
	long long ans = 0;
	while(l <= r) {
		long long mid = (l + r) / 2;
		if(judge(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
