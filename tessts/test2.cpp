#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		int tmp  = 0;
		int now = i;
		while (now > 0) {
			tmp += ((now % 10) * (now % 10) * (now % 10) * (now % 10));
			now /= 10;
		}
		if (tmp == i) {
			cout << i << " ";
		}
	}
	return 0;
}