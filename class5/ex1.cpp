#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	stack<int> ans;
	int sum = 0;
	for (int i = 0; s[i] != '@'; i++) {
		if (s[i] == '.') {
			ans.push(sum);
			sum = 0;
		}
		if (s[i] >= '0' && s[i] <= '9') {
			sum = sum * 10 + (s[i] - '0');
		} else {
			if (s[i] == '*') {
				int a = ans.top();
				ans.pop();
				int b = ans.top();
				ans.pop();
				ans.push(a * b);
			} else if (s[i] == '/') {
				int a = ans.top();
				ans.pop();
				int b = ans.top();
				ans.pop();
				ans.push(b / a);
			} else if (s[i] == '+') {
				int a = ans.top();
				ans.pop();
				int b = ans.top();
				ans.pop();
				ans.push(a + b);
			} else if (s[i] == '-') {
				int a = ans.top();
				ans.pop();
				int b = ans.top();
				ans.pop();
				ans.push(b - a);
			}
		}
	}
	cout << ans.top();
	return 0;
}