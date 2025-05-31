#include <iostream>
using namespace std;
long long calc(long long a,long long b,long long p) {
	if(b == 0) {
		return 1;
	}
	if(b == 1) {
		return a % p;
	}
	if(b % 2) {
		long long res = calc(a,b / 2,p);
		return res * res % p * (a % p) % p;
	}
	else {
		long long res = calc(a,b / 2,p);
		return res * res % p;
	}
}

int main() {
	int t;
	cin>>t;
	while(t --) {
		long long n,m;
		cin>>n>>m;
		cout << calc(2,(n - 1) * (m - 1),998244353) << endl;
	}
	return 0;
}
