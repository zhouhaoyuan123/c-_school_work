#include <iostream>
using namespace std;
int f[101];

int main() {
	int n;
	cin>>n;
	f[2] = 2;
	for(int i = 3;i<=n;i++) {
		f[i] = f[i - 1] + i;
	}
	cout << f[n];
	return 0;
}
