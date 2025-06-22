#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	if(!prev_permutation(a + 1,a + 1 + n)) {
		cout << "ERROR" << endl;
		return 0;
	}
	for(int i = 1;i<=n;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
