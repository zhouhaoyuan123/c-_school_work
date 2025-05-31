#include <iostream>
#include <cmath>
using namespace std;
long long a[105];
long long power(int base,int x) {
	long long ans = 1;
	for(int i = 1;i<=x;i++) {
		ans *= base;
	}
	return ans;
}

int main() {
	int n,k;
	cin>>n>>k;
	__int128 lim = power(10,k) - 1;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	__int128 ans = 1;
	for(int i = 1;i<=n;i++) {
		if(a[i] > lim) {
			ans = 1;
		}
		else {
			if(lim / ans < a[i]) {
				ans = 1;
			}
			else {
				ans *= a[i];
			}
		}
	}
	cout << (long long) ans << endl;
	return 0;
}
