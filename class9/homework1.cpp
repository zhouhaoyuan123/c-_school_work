#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		set<string> s;
		multimap<string, string> data;
		for (int i = 0; i < n; i++) {
			string t;
			cin >> t;
			string t2;
			cin >> t2;
			s.insert(t);
			s.insert(t2);
			data.insert(pair<string, string>(t, t2));
		}
		for (auto &it : data) {
			if (s.count(it.second)) {
				s.erase(it.second);
			}
		}
		if (s.size() == 1) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
		cin >> n;
	}
	return 0;
}
