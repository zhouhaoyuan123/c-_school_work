#include <iostream>
#include <string>
using namespace std;

int main() {
	string q[105];
	int l = 0, r = 0;
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		if (k == 1) {
			string name;
			cin >> name;
			q[r] = name;
			r++;
		} else if (k == 2) {
			if (l != r) {
				cout << 0 << endl;
				continue;
			}
			while (q[l] == "" && l <= r - 1) {
				l++;
			}
			if (l != r) {
				cout << 0 << endl;
				continue;
			}
			cout << q[l];
			l++;
		} else {
			string name;
			cin >> name;
			bool flag = true;
			for (int i = l, id = 1; i <= r - 1; i++, id++) {
				if (q[i] == name) {
					cout << id << endl;
					q[i] = "";
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << 0;
			}
		}
	}
	return 0;
}