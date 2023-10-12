#include <iostream>
using namespace std;
const int mod = 1e9+7;

int main() {
	int n;
	cin>>n;
	if(n == 1) {
		cout << 3;
		return 0;
	}
	int nbc,na;
	int obc,oa;
	obc = 0;
	oa = 1;
	for(int i = 1;i<n;i++) {
		na = obc % mod;
		nbc = (oa * 2 % mod + obc) % mod;
		oa = na;
		obc = nbc;
	}
	cout << ((obc+obc) % mod + obc) % mod;
	return 0;
}
