#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k;int a[25];int ans;
void dfs(int u,int cnt) {
	if(u == k + 1) {
		if(cnt == n) {
			ans++;
		} 
		return;
	}
	if( cnt > n ) {
		return;
	}
	for(int i = a[u - 1];i<=n - cnt;i++) {
		if(u == 1 && i == n) {
			continue;
		}
		a[u] = i;
		dfs(u+1,cnt+i);
	}
}

int main() {
	a[0] = 1;
	cin>>n>>k;
	dfs(1,0);
	cout << ans;
	return 0;
}
