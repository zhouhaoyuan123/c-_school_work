#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
	bool parent;
	vector<int> child;
};

int main() {
	int n;
	cin >> n;
	map<int, node> m;
	vector<int> tmp;
	int max = 0;
	bool flag = true;
	int root = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		(m[y].child).push_back(x);
		m[x].parent = true;
		if (flag) {
			max = y;
			m[y].parent = false;
			flag = false;
			root = y;
			continue;
		}
		if (m[y].parent == false) {
			root = y;
		}
		if ((m[max].child).size() < (m[y].child).size()) {
			max = y;
		}
	}
	cout << root << endl;
	cout << max << endl;
	for (int i = 0; i < (m[max].child).size(); i++) {
		cout << m[max].child[i] << " ";
	}
	return 0;
}