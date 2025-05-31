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
	long long a,b,p;
	cin>>a>>b>>p;
	cout << a <<"^"<<b<<" mod "<<p <<"="<<calc(a,b,p) << endl;
	return 0;
}
