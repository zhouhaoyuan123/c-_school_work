#include <iostream>
#include <string>
using namespace std;

bool f(string a, string b) {
	//基线条件（==）
	if (a.size() == 1 && b.size() == 1) {
		if (a == b) {
			return true;
		}
		return false;
	}
	if (a == b) {
		return true;
	} else if (a.size() == b.size()
	           && a.size() % 2 == 0) {
		string a1 = a.substr(0, a.size() / 2);
		string a2 = a.substr(a.size() / 2, a.size() / 2);
		string b1 = b.substr(0, b.size() / 2);
		string b2 = b.substr(b.size() / 2, b.size() / 2);
		if ((a1 == a2) && (b1 == b2)) {
			return false;
		}
		cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
		return (f(a1, b1) && f(a2, b2)) || (f(a1, b2) && f(a2, b1));
	} else if (a.size() % 2 != 0
	           && b.size() % 2 != 0) {
		string a1 = a.substr(0, a.size() / 2 + 1);
		string a2 = a.substr(a.size() / 2 + 1, a.size() / 2);
		string b1 = b.substr(0, b.size() / 2 + 1);
		string b2 = b.substr(b.size() / 2 + 1, b.size() / 2 );
		if ((a1 == a2) && (b1 == b2)) {
			return false;
		}
		cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
		return f(a1, b1) && f(a2, b2) || f(a1, b2) && f(a2, b1);
	} else {
		return false;
	}
}

int main() {
	string a, b;
	cin >> a >> b;
	if (f(a, b)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}