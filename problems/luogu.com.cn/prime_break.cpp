#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue<long long> q;

int main() {
	long long n,m;
	cin>>n>>m;
	long long tmp = __gcd(n,m);
	long long ans = 0;
	int tmp2 = tmp;
	int i;
	for(i = 1;1ll * i * i<=tmp;i++) {
		if(tmp % i == 0) {
			ans ++;
			if(i == 1) continue;
			while(tmp % i== 0) {
				tmp /= i;
			}
		}
	}
	if(tmp > 1) {
		ans ++;
	}
	cout << ans << endl;
	return 0;
}
