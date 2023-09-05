#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	freopen("friend.in","r",stdin);
	freopen("friend.out","w",stdout);
	int n,d;
	cin>>n>>d;
	long long r[n];
	for(int i = 0;i<n;i++){
		long long p;cin>>p;r[i] = p;
	}
	sort(r,r+n);
	long long ans = 0;
	for(int i = 0;i<n;i++) {
		int index = lower_bound(r,r+n,r[i] +  d) - r;
		if(index == n) {
			index = n - 1;
		}
		if(r[index] > r[i] + d) {
			index --;
		}
		ans += index - i;
	}
	cout << ans;
	return 0;
}
