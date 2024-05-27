#include <iostream>
#include <string>
using namespace std;
bool vis[105];

int main() {
	string s;
	cin>>s;
	for(int i = 0;i<=s.size() - 1;i++) {
		if(s[i] == '(' || s[i] == '[') continue;
		for(int j = i - 1;j>=0;j--) {
			if(!vis[j]) {
				if(s[j] == '(') {
					if(s[i] == ')') {
						vis[j] = 1;
						vis[i] = 1;
						break;
					}
					break;
				}
				else if(s[j] == '[') {
					if(s[i] == ']') {
						vis[j] = 1;
						vis[i] = 1;
						break;
					}
					break;
				}
				else {
					continue;
				}
				break;
			}
		}
	}
	for(int i = 0;i<s.size();i++) {
		if(!vis[i]) {
			if(s[i] == '(' || s[i] == ')') {
				cout << "()";
			}
			else if(s[i] == '[' || s[i] == ']') {
				cout << "[]";
			}
		}
		else {
			cout << s[i];
		}
	}
	return 0;
}
