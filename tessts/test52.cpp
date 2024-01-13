#include <iostream>
using namespace std;
int f[100005];

int main() {
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	f[0] = a,f[1] = b,f[2] = c;
	for(int i = 3;i<n;i++) {
		f[i] = (f[i - 2] + f[i - 3]) % 10007;
	}
	cout << f[n - 1];
	return 0;
}
