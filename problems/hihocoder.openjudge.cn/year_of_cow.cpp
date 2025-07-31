#include <iostream>
#include <algorithm>
using namespace std;
int num[70005];
int b[70005],gap[70005];

int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	for(int i = 1;i<=n;i++) {
		b[i] = num[i] / 12 + 1;
	}
	for(int i = 0;i<n;i++) {
		gap[i + 1] = max(0,b[i + 1] - b[i] - 1);
	}
	sort(gap+1,gap+n+1,greater<int>());
	long long ans = 1ll * b[n] * 12;
	for(int i = 1;i<k;i++) {
		ans -= gap[i] * 12;
	}
	cout << ans << endl;
	return 0;
}
