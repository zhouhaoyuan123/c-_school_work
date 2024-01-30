#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i = 1;;i++) {
		for(int j = i;(j+1) * j / 2<=n + 3 * i;j++) {
			if((j + 1) * j / 2 - 3 * i == n) {
				cout << i <<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
