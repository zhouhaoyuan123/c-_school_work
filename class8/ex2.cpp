#include <iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m2;
		cin >> n >> m2;
		map<int, int> m;
		map<int, int> child;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t; //Êý×Ö
			m[t]++;//Í°ÅÅ
		}
		for (int j = 0; j < m2; j++) {
			int t;
			cin >> t;
			child[t] ++;
		}
		bool flag = true;
		for (map<int, int>::iterator it = child.begin(); it != child.end(); it++) {
			if (m.find(it->first) != m.end()) {
				if (m[it->first] - child[it->first] < 0) {
					cout << "No" << endl;
					flag = false;
					break;
				}
			} else {
				cout << "No" << endl;
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes" << endl;
		}
	}
	return 0;
}