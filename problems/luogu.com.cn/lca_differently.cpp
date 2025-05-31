#include <iostream>
#include <algorithm>
using namespace std;
long long num[100005];
int main() {
	int n;
	long long m;
	cin>>n>>m;
	long long ans = 1;
	for(int i = 1;i<=n;i++) {
		long long x;
		cin>>x;
		num[i] = x;
		if(x % 2) {
			cout << 0 << endl;
			return 0;
		}
		if(i == 1) {
			ans = x / 2;
			continue;
		}
		long long tmp = ans * (x / 2) / __gcd(ans,x / 2);
		if(tmp > m) {
			cout << 0 << endl;
			return 0;
		}
		ans = tmp;
	}
	for(int i = 1;i<=n;i++) {
		if((ans / (num[i] / 2)) % 2 == 0 ) {
			cout << 0 << endl;
			return 0;
		}
	}
	long long res = (m / ans - 1) / 2;
	if(res < 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << res + 1 << endl;
	return 0;
}
