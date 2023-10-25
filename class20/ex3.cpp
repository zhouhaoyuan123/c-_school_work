#include <iostream>
using namespace std;
int a[101];

int main() {
	int n,m;
	cin>>n>>m;
	a[2] = 1;
	a[3] = 2;
	int i;
	for(i = 4;i<=m-n + 1;i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	cout << a[i - 1];
	return 0;
}
