#include <iostream>
using namespace std;

int main() {
	int n, cl = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		if (n1 == (cl + 2) || n1 == cl) {
			ans += n3;
			cl  = n1;
		}
	}
	cout << ans;
	return 0;
}