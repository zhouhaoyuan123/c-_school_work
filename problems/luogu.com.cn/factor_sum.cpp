#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	while(m --) {
		int x;
		cin>>x;
		int cnt = 0;
		long long ans = 0;
		for(int i = 1;i * i <= x;i++) {
			if(x % i == 0) {
				cnt ++;
				ans += i;
				if(i * i != x) {
					cnt ++;
					ans += (x / i);
				}
			}
		}
		cout << cnt << " " << ans << endl;
	}
	return 0;
}
