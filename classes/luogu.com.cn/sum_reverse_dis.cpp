#include <iostream>
using namespace std;
long long dis[5000005];
long long num[5000005];

int main() {
	int n,p;
	cin>>n>>p;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		dis[i] = num[i] - num[i - 1];
	}
	for(int i = 1;i<=p;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		dis[y+1] -= z;
		dis[x] += z;
	}
	long long ans2 = 5e9 + 10;
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		ans += dis[i];
		ans2 = min(ans2,ans);
	}
	cout << ans2;
	return 0;
}
