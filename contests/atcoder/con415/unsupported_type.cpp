#include <iostream>
using namespace std;
int a[105];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	int x;
	cin>>x;
	for(int i = 1;i<=n;i++) {
		if(a[i] == x) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
