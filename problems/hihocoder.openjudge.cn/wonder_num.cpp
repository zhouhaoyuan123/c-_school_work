#include <iostream>
#include <cmath>
using namespace std;
long long calc(long long l) {
	if(l == 0) return 0;
	long long num = sqrt(l);
	num += 2;
	while(num * num > l) {
		num --;
	}
	long long ans = (num - 1) * 3;
	long long tmp = num * num;
	while(tmp <= l) {
		tmp += num;
		ans ++;
	}
	return ans;
}

int main() {
	int T;
	cin>>T;
	while(T --) {
		long long l,r;
		cin>>l>>r;
		cout << calc(r) - calc(l - 1) << "\n";
	}
	cout << endl;
	return 0;
}
