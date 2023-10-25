#include <iostream>
#include <sstream>
using namespace std;

string f(string n) {
	stringstream ss;
	if (n.size() == 1 && n[0] >= '0' && n[0] <= '9') {
		return n;
	}
	if (n.size() % 2 == 0) {
		string a = n.substr(0, n.size() / 2);
		string b = n.substr(n.size() / 2, n.size() / 2);
		ss << a;
		int t1, t2;
		ss >> t1;
		ss.clear();
		ss.str("");
		ss << b;
		ss >> t2;
		ss.clear();
		ss.str("");
		ss << (t1 + t2);
		string tmp;
		ss >> tmp;
		ss.clear();
		ss.str("");
		return f(tmp);
	} else if (n.size() % 2 != 0) {
		string a = n.substr(0, n.size() / 2 );
		string b = n.substr(n.size() / 2 + 1, n.size() / 2);
		ss << a;
		int t1, t2;
		ss >> t1;
		ss.clear();
		ss.str("");
		ss << b;
		ss >> t2;
		ss.clear();
		ss.str("");
		ss << (t1 * t2);
		string tmp;
		ss >> tmp;
		ss.clear();
		ss.str("");
		return f(tmp);
	}
}

int main() {
	string s;
	cin >> s;
	cout << f(s);
	return 0;
}