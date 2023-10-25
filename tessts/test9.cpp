#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string x, string y) {
	return x[0] < y[0];
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v[n];
	for (int i = 0; i < m; i++) {
		int s;
		string name;
		cin >> s >> name;
		v[s - 1].push_back(name);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].size() == 0) {
			cout << i + 1 << " 0" << endl;
			continue;
		}
		sort(v[i].begin(), v[i].end(), cmp);
		cout << i + 1 << " " << v[i].size() << " ";
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}