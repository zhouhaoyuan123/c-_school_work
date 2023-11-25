#include <iostream>
#include <cstdio>
using namespace std;
int height[25];int a[25];int n,b;int minn = -1;
void dfs(int u) {
	if(u == n ) {
		int cnt = 0;
		for(int i = 0;i<n;i++) {
			if(a[i]) {
				cnt+=height[i];
			}
		}
		if(cnt > b) {
			cout << "1";
			if(minn == -1) {
				minn = cnt - b;
			}
			if (minn > cnt - b) {
				minn = cnt-b;
			}
		}
		return;
	}
	a[u] = 0;
	dfs(u+1);
	a[u] = 1;
	dfs(u+1);
}

int main() {
	//freopen("shelf.in","r",stdin);
	//freopen("shelf.out","w",stdout);
	cin>>n>>b;
	for(int i = 0;i<n;i++) {
		cin >> height[i];
	}
	dfs(0);
	cout << minn;
	return 0;
}
