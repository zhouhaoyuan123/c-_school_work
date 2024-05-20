#include <iostream>
using namespace std;
long long num[100005];

int main() {
	int n,x;
	cin>>n>>x;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		if(num[i] + num[i + 1] > x) {
			ans += (num[i] + num[i + 1] - x);
			if(num[i + 1] >= num[i] + num[i + 1] - x) {
				num[i + 1] -= (num[i] + num[i + 1] - x);
			}
			else {
				num[i] -= (x - num[i + 1]);
				num[i+1] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
