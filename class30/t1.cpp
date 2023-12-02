#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;int a[25];int vis[25];
void dfs(int u) {
	if(u == n + 1) {
		for(int i = 1;i<=n;i++) {
			cout << a[i];
		}
		cout << endl;
		return;
	}
	for(int i = 1;i<=n;i++) {
		if(!vis[i]) {
			vis[i] = 1;
			a[u] = i;
			dfs(u+1);
			vis[i] = 0;
		}
	}
}

int main() {
	cin>>n;
	dfs(1);
	return 0;
}
