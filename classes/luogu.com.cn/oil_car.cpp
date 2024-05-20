#include <iostream>
#include <cmath>
using namespace std;
int num[100005];
int dis[100005];

int main() {
	int n,d;
	cin>>n>>d;
	for(int i = 2;i<=n;i++) {
		cin>>dis[i];
	}
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	num[0] = 1e5 + 5;
	int last = 0;
	long long ans = 0;double buf = 0;
	for(int i = 1;i<n;i++) {
		if(num[last] > num[i]) {
			ans +=ceil(buf) * num[last];
			buf = ceil(buf) - buf;
			buf = -buf;
			last = i;
		}	
		buf += 1.0 * dis[i + 1] / d;
	}
	ans += (ceil(buf) * num[last]);
	cout << ans;
	return 0;
}
