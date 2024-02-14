#include <iostream>
using namespace std;
int n,a[15],vis[15];
void dfs(int step) {
	if(step == n) {
		for(int i = 0;i<n;i++) {
			cout << a[i];
		}
		cout << endl;
		return;
	}
	for(int i = 1;i<=n;i++) {
		if(!vis[i]) {
			vis[i] = 1;
			a[step] = i;
			dfs(step+1);
			vis[i] = 0;
		}
		
	}
}

int main() {
	cin>>n;
	dfs(0);
	return 0;
}
