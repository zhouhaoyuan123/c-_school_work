#include <iostream>
using namespace std;
int n,k;
int tree[100005];
bool judge(int lim) {
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		ans += tree[i] / lim;
	}
	return ans >= k;
}

int main() {
	//int n;
	cin>>n>>k;
	for(int i = 1;i<=n;i++) {
		cin>>tree[i];
	}
	int l = 1,r = 1e8;
	int ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(judge(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
