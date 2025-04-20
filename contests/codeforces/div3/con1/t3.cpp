#include <iostream>
using namespace std;
bool judge(int n) {
	if(n < 2) {
		return false;
	}
	for(int i = 2;i * i <= n;i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin>>t;
	while(t -- ) {
		int n,k;
		cin>>n>>k;
		if(n > 1 && k > 1 ) {
			cout << "NO" << endl;
		}
		else if(n > 1) {
			if(judge(n)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			k --;
			while(k --) {
				n *= 10;
				n += n;
			}
			if(judge(n)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
