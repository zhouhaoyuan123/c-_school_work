#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	int cnt = 0,cnt2 = 0;
	for(int i = 0;i<s.size();i++) {
		if(s[i] == '.') {
			cnt ++;
		}
	}
	for(int i = 0;i<s.size();i++) {
		if(s[i] == '#') {
			cout << "#";
		}
		else if(((i > 0 && s[i - 1] == '#') || i == 0)) {
			cnt2 ++;
			cout << "o";
		}
		else {
			cout << ".";
		}
	}
	cout << endl;
	return 0;
}
