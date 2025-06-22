#include <iostream>
using namespace std;

int main() {
	int n,s;
	cin>>n>>s;
	int buf = 0;
	for(int i = 1;i<=n;i++) {
		int x;
		cin>>x;
		if(x - buf > s) {
			cout << "No" << endl;
			return 0;
		}
		buf = x;
	}
	cout << "Yes" << endl;
	return 0;
}
