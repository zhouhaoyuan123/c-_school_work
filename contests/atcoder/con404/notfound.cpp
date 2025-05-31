#include <iostream>
#include <string>
using namespace std;
bool vis[30];

int main() {
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++) {
		vis[s[i] - 'a'] = 1;
	}
	for(int i = 0;i<26;i++) {
		if(!vis[i]) {
			cout << char(i + 'a') << endl;
			return 0;
		}
	}
	return 0;
}
