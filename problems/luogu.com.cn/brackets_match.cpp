#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> st;
	string s;
	getline(cin,s);
	for(int i = 0;i<s.size() - 1;i++) {
		if(s[i] == '(') {
			st.push(s[i]);
		}
		else if(s[i] == ')') {
			if(!st.empty()) {
				st.pop();
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	if(st.empty()) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
