#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int num[n],maxn = 0,minn = 1e6;
	for(int i = 0;i<n;i++) {
		cin>>num[i];
		maxn = max(maxn,num[i]);
		minn = min(minn,num[i]);
	}
	int l = minn,r = maxn,mid;
	while(l <= r) {
		mid = (l+r) / 2;
		int cnt = 0;
		for(int i = 0;i<n;i++) {
			if(num[i] > mid) {
				cnt++;
			}
		}
		if(cnt > n/2) {
			l = mid - 1;
		}
		else {
			r = mid;
		}
	}
	return 0;
}
