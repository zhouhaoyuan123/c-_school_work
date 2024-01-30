#include <iostream>
#include <string>
using namespace std;
string keyboard[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int presscnt[27];

int main() {
	string s;
	getline(cin,s);
	for(int i = 0;i<10;i++) {
		for(int j = 0;j<keyboard[i].size();j++) {
			if(keyboard[i][j] == ' ') {
				presscnt[0] = j+1;
			}
			else {
				presscnt[keyboard[i][j] - 'a' + 1] = j+1;
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<s.size();i++) {
		if(s[i] == ' ') {
			ans += presscnt[0];
		}
		else {
			ans += presscnt[s[i] - 'a' + 1];
		}
	}
	cout << ans;
	return 0;
}
