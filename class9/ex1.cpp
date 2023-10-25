#include <set>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	for (auto &it : s) {
		cout << it << endl;
	}
	return 0;
}