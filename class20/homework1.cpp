#include <iostream>
using namespace std;
long long calc1(int x,int y) {
	long long ans = 1;
	for(int i = y,cnt = 1;cnt<=x;i--,cnt++) {
		ans *= i;
	}
	for(int i = 1;i<=x;i++) {
		ans /= i;
	}
	return ans;
}
long long calc2(int x,int y) {
	long long ans = 1;
	for(int i = 1;i<=x;i++) {
		ans *= y;
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 0;i<=n;i+=2) {
		if(i == 0) {
			if(n == 1) {
				ans+=9;
				continue;
			}
			ans += 8 * calc2(n - 1,9) % 1111;
			continue;
		}	
		ans+= ((calc1(i,n) - calc1(i,n - 1)) * calc2(n - i,9) + calc1(i,n-1) * 8 * calc2(n-i-1,9)) % 1111;
	}
	cout << ans;
	return 0;
}
