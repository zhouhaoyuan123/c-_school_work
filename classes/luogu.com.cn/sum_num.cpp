#include <iostream>
using namespace std;
long long num[100005];
long long ans[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	for(int i = 1;i<=n;i++) {
		ans[i] = ans[i - 1] + num[i];
	}
	int m;
	cin>>m;
	for(int i = 1;i<=m;i++) {
		int l,r;
		cin>>l>>r;
		cout << ans[r] - ans[l - 1]<<endl;
	}
	return 0;
}
