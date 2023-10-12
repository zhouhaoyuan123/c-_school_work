#include <iostream>
using namespace std;
const int mod = 100003;
int f[100005];
int main() {
	int n,k;
	cin>>n>>k;
	f[0] = 1,f[1] = 1;
	for(int i = 2;i<=n;i++) {
		int cntn = 0;
		for(int j = i - 1,cnt = 0;j>=0 && cnt < k;j--,cnt++) {
			cntn += f[j];
			cntn %= mod;
		}
		f[i] = cntn;
	}
	cout << f[n] % mod;
	return 0;
}
