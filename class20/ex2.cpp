#include <iostream>
using namespace std;
int a[101];

int main() {
	int n;
	cin>>n;
	a[1] = 1;
	int i,j;
	for(i = 2,j = 1;j<=n;j++,i++) {
		a[i] = a[i - 1] * 2  + 1;
	}
	cout << a[i - 1];
	return 0;
}
