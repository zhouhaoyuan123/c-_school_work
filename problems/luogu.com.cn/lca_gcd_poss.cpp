#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x,y;
	cin>>x>>y;
	int ans = 0;
	for(int i = x;i<=y;i++) {
		if(i % x == 0 && y % i == 0) {
			if(__gcd(i,y / i * x) == x) {
				ans ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
