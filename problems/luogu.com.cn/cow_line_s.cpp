#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[25];
int ans[25];
bool vis[25];
long long fac[25];
void reverse_cantor(int n,long long cnt) {
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	for(int i = 1;i<=n;i++) {
		long long tmp = cnt / fac[n - i];
		int j;
		for(j = 1;j<=n;j++) {
			if(vis[j]) continue;
			if(tmp <= 0) break;
			tmp --;
		}
		vis[j] = 1;
		ans[i] = j;
		cnt %= fac[n - i];
	}
}


int main() {
	int n,q;
	cin>>n>>q;
	fac[0] = 1;
	for(int i = 1;i<=20;i++) {
		fac[i] = fac[i - 1] * i;
	}
	while(q --) {
		char op;
		cin>>op;
		if(op == 'P') {
			long long tmp;
			cin>>tmp;
			reverse_cantor(n,tmp - 1);
			for(int i = 1;i<=n;i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		else {
			memset(num,0,sizeof(num));
			for(int i = 1;i<=n;i++) {
				cin>>num[i];
			}
			long long ans = 0;
			for(int i = 1;i<=n;i++) {
				int tmp = 0;
				for(int j = 1;j<i;j++) {
					if(num[j] < num[i]) {
						tmp ++;
					}
				}
				ans += (num[i] - tmp - 1) * fac[n - i];
			}
			cout << ans + 1 << endl;
		}
	}
	
	return 0;
}
