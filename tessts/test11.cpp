#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	int cnt = 0;
	cin >> a >> b;
	if (a > b) {
		string tmp = b;
		b = a;
		a = tmp;
	}
	if (a == b) {
		cout << 0;
		return 0;
	}
	while (true) {
		next_permutation(a.begin(), a.end());
		if (a == b) {
			if (cnt == 0) {
				cout << 1;
				return 0;
			}
			cout << cnt - 1;
			break;
		}
		cnt++;
	}
	return 0;
}