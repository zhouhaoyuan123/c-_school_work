#include <iostream>
using namespace std;
int table[100005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int i2, j;
		cin >> i2 >> j;
		table[i2] = j;
	}
	int p = table[1];
	cout << 1 << endl;
	while (true) {
		if (p == 0) {
			break;
		}
		cout << p << endl;
		p = table[p];
	}
	return 0;

}