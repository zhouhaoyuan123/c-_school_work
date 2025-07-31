#include <iostream>
using namespace std;
int a[1005];

int main() {
	int n,m;
	cin>>n>>m;
	int sum = 0;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
		sum += a[i];
	}
	if(sum <= m) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
