#include <iostream>
using namespace std;

int main() {
	int a = 1498, b = 902, l = 10, max = -1, maxa = l, maxb = 1;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			cout << i << ":" << j << "|" << ((i / j - a / b) < (maxa / maxb - a / b) && (a / b - i / j) <= 0) << endl;
			if ((i / j - a / b) < (maxa / maxb - a / b)) {
//				max = /**/;
				if ((1.0 * i / j) >= (1.0 * a / b)) {
					maxa = i;
					maxb = j;
				}
			}

		}

	}
	cout << maxa << ":" << maxb;
	return 0;
}
