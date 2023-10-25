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
			//letter.push(s[i]);
			char l = letter.top();
			bool flag = false;
			for (; i < s.size(); i++) {
				if (s[i] == l) {
					flag = true;
				} else {
					break;
				}
			}
			if (flag) {
				letter.pop();
				if (i < s.size()) {
					if (letter.size() > 0) {
						if (letter.top() == s[i]) {
							i--;
							continue;
						}
					}
					letter.push(s[i]);
				}
			} else {
				if (letter.size() > 0) {
					if (letter.top() == s[i]) {
						i--;
						continue;
					}
				}
				letter.push(s[i]);
			}
		} else {
			letter.push(s[i]);
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