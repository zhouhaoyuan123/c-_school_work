#include <iostream>
#include <algorithm>
using namespace std;
long long num[105];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	num[0] = -1;
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		ans = max(ans,min(num[i],1ll * n - i + 1));
	}
	cout << ans << endl;
	return 0;
}
