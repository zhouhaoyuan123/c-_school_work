#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
long long n;
int prime[20] = {0,2,3,5,7,11,13,17,23,29,31,37};
long long maxn = 0;
int step_lim = 0;
void dfs(int step,long long cnt,int j,int k) {
	if(step > step_lim) {
		maxn = max(maxn,cnt);
		return;
	}
	if(j == 0 || cnt > n) return;
	if(cnt * prime[step] <= n && j > k) dfs(step,cnt * 1ll * prime[step],j,k+1);
	if(k > 0) dfs(step+1,cnt,k,0);
}

int main() {
	cin>>n;
	long long tmp = 1;
	for(int i = 1;i<=11;i++) {
		if(tmp * prime[i] > n) {
			step_lim = i - 1;
			break;
		}
		tmp *= prime[i];
	}
	dfs(1,1,log2(n),0);
	cout << maxn << endl;
	return 0;
}
