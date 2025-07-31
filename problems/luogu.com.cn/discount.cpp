#include <iostream>
#include <algorithm>
using namespace std;
int num[200005];

int main() {
	int n,k,x;
	cin>>n>>k>>x;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		int tmp = num[i];
		num[i] = num[i] - x * min(k,num[i] / x);
		k -= min(k,tmp / x);
	}
	sort(num+1,num+1+n,greater<int>());
	for(int i = 1;i<=min(n,k);i++) num[i] = 0;
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		ans += num[i];
	}
	cout << ans << endl;
	return 0;
}
