#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	string op = s.substr(0,s.find("="));
	string res = s.substr(s.find("=") + 1);
	if(res == "?") {
		long long a = 0,b = 0;
		int i;
		for(i = 0;i<op.size();i++) {
			if(!(op[i] >= '0' && op[i] <= '9')) break;
			a = a * 10 + op[i] - '0';
		}
		int j = i;
		i ++;
		for(;i<op.size();i++) {
			b = b * 10 + op[i] - '0';
		}
		if(op[j] == '+') {
			cout << a + b << endl;
		}
		else if(op[j] == '-') {
			cout << a - b << endl;
		}
		else if(op[j] == '*') {
			cout << a * b << endl;
		}
		else {
			cout << a / b << endl;
		}
	}
	else {
		int pos = op.find("?");
		long long c = stoll(res);
		if(pos == 0) {
			long long b = stoll(s.substr(2));
			if(s[1] == '+') {
				cout << c - b << endl;
			}
			else if(s[1] == '-') {
				cout << c + b << endl;
			}
			else if(s[1] == '*') {
				cout << c / b << endl;
			}
			else {
				cout << c * b << endl;
			}
		}
		else if(pos == op.size() - 1) {
			long long a = stoll(s.substr(0,op.size() - 2));
			if(s[op.size() - 2] == '+') {
				cout << c - a << endl;
			}
			else if(s[1] == '-') {
				cout << a - c << endl;
			}
			else if(s[1] == '*') {
				cout << c / a << endl;
			}
			else {
				cout << a / c << endl;
			}
		}
		else {
			long long a = stoll(s.substr(0,pos));
			long long b = stoll(s.substr(pos + 1));
			if(a + b == c) {
				cout << "+" << endl;
			}
			else if(a / b == c) {
				cout << "/" << endl;
			}
			else if(a * b == c) {
				cout << "*" << endl;
			}
			else {
				cout << "-" << endl;
			}
		}
	}
	return 0;
}
