#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int tmp = 0, tmp2 = v[0];
	for (int i = 0; i <= v.size(); i++) {
		if (tmp2 != v[i]) {
			if (tmp == 1) {
				cout << tmp2;
				return 0;
			}
			tmp2 = v[i];
			tmp = 0;
		}
		tmp++;
	}
	return 0;
}