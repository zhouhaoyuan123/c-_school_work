#include <iostream>
#include <list>
using namespace std;
int cnt = 0, n = 0, m = 0;
list<int> l;

bool if_remove(const int a) {
	cnt++;
	if (m == cnt && l.size() > 1) {
		cnt = 0;
		return true;
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		l.push_back(i);
	}
	while (l.size() > 1) {
		l.remove_if(if_remove);
	}
	list<int>::iterator it = l.begin();
	cout << *it;
	return 0;
}