#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s, ans = "";
	cin >> s;
	stack<char> letter;
	for (int i = 0; i < s.size(); i++) {
		if (!letter.empty()) {
			letter.push(s[i]);
			char l = letter.top();
			bool flag = false;
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] == l) {
					flag = true;
				} else {
					i = j - 1;
					break;
				}
			}

			if (flag) {
				letter.pop();
			}
		} else {
			letter.push(s[i]);
			char l = letter.top();
			bool flag = false;
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] == l) {
					flag = true;
				} else {
					i = j - 1;
					break;
				}
			}
			if (flag) {
				letter.pop();
			}
		}
	}
	while (!letter.empty()) {
		ans += letter.top();
		letter.pop();
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	return 0;
}