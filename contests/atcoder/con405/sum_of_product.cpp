#include <iostream>
using namespace std;

long long cnt[300005];
long long num[300005];
int main() {
	int n;
	cin>>n;
	cnt[0] = 0;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		cnt[i] = num[i];
		cnt[i] += cnt[i - 1];
	}
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		ans += cnt[i - 1] * num[i];
	}
	cout << ans << endl;
	return 0;
}
