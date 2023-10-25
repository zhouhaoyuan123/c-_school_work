#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	list<int> l;
	//map<int,list<int> ::iterator> m;
	l.push_back(1);
	//m[1] = l.begin();
	for (int i = 2; i <= n; i++) {
		int k, p;
		cin >> k >> p; //Ä¿±ê,×´Ì¬
		if (p == 0) {
			//×ó±ß
			auto it = find(l.begin(), l.end(), k);
			l.insert(it, i);
		} else {
			//ÓÒ±ß
			auto it = find(l.begin(), l.end(), k);
			advance(it, 1);
			l.insert(it, i);
		}
	}
	//delete
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int q;
		cin >> q;
		l.remove(q);
	}
	for (auto &it : l) {
		cout << it << " ";
	}
	return 0;
}