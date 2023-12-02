#include <iostream>
#include <cmath>
using namespace std;
int n;int s[16],b[16],a[16];int minn = -1;
void dfs(int u) {
	if(u == n) {
		int ts = 1,tb = 0;int cnt = 0;
		for(int i = 0;i<n;i++) {
			if(a[i]) {
				cnt++;
				ts *= s[i];
				tb += b[i];
			}
		}
		if(cnt < 1) {
			return;
		}
		if(minn == -1) {
			minn = abs(ts - tb);
		}
		if(minn > abs(ts-tb)) {
			minn = abs(ts-tb);
		}
		return;
	}
	a[u] = 0;
	dfs(u + 1);
	a[u] = 1;
	dfs(u+1);
}

int main() {
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>s[i]>>b[i];
	}
	dfs(0);
	cout << minn;
	return 0;
}
