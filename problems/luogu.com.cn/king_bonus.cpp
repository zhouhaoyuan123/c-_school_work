#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct hands {
	int l,r;	
}hand[10005];
bool cmp(hands x,hands y) {
	return 1.0 * x.l / y.r < 1.0 * y.l / x.r;
}
double ans[10005];

int main() {
	int n;
	cin>>n;
	for(int i = 0;i<=n;i++) {
		cin>>hand[i].l >> hand[i].r;
		//ans[i] = 1.0 * hand[i][0] / hand[i][1];
	}
	sort(hand + 1,hand+1+n,cmp);
	long long tmp = hand[0].l , ans2 = 0;
	for(int i = 1;i<=n;i++) {
		if(ans2 < 0) {
			cout << -1;
			return 0;
		}
		ans2 = max(ans2,(long long)(floor(1.0 * tmp / hand[i].r)));
		tmp *= hand[i].l;
	}
	cout << ans2;
	return 0;
}
