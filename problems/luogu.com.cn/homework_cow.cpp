#include <iostream>
#include <cstring>
using namespace std;
int num[100005];
int sum[100005],minn[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	minn[n + 1] = 1e9;
	for(int i = n;i>=1;i--) {
		sum[i] = sum[i + 1] + num[i];
		minn[i] = min(minn[i + 1],num[i]);
	}
	double maxn = 0;
	for(int i = 2;i<=n;i++) {
		maxn = max(maxn,1.0 * (sum[i] - minn[i]) / (n - i));
	}
	for(int i = 2;i<=n;i++) {
		if(1.0 * (sum[i] - minn[i]) / (n - i) == maxn) {
			cout << i - 1 << "\n";
		}
	}
	cout << endl;
	return 0;
}
