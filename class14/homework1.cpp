#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int d;
	cin >> d;
	bool color[int(pow(2, d))] = {0};
	for (int i = 0; i < 5; i++) {
		int index = 1;
		bool flag = 0;
		while (index <= int(pow(2, d)) - 1) {
			if (!color[index]) {
				flag = 0;
				index = 2 * index;
				color[index / 2] = !color[index / 2];
			} else {
				flag = 1;
				index = 2 * index + 1;
				color[(index - 1) / 2] = !color[(index - 1) / 2];
			}
			if (index >= int(pow(2, d)) - 1 && flag == 0) {
				cout << index / 2 << endl;
			} else if (index >= int(pow(2, d)) - 1 && flag == 1) {
				cout << (index - 1) / 2 << endl;
			}
		}
	}
	return 0;
}