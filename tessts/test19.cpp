#include <iostream>
#include <stack>
using namespace std;

struct pteam {
	int first;
	int last;
};

int main() {
	string s;
	cin >> s;
	stack<pteam> brackets;
	stack<pteam> ans;
	if (s.size() % 2 != 0) {
		cout << "No";
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			pteam t;
			t.first = i + 1;
			brackets.push(t);
		} else {
			if (brackets.size() == 0) {
				cout << "No";
				return 0;
			}
			pteam t = brackets.top();
			t.last = i + 1;
			if (brackets.size() == 0) {
				cout << "No";
				return 0;
			}
			brackets.pop();
			ans.push(t);
		}
	}
	if (brackets.size() > 0) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		while (!ans.empty()) {
			pteam t = ans.top();
			cout << t.first << " " << t.last << endl;
			ans.pop();
		}
	}
	return 0;
}