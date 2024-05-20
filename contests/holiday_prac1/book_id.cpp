#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	long long buf = 0;
	for(int i = 0,j = 1;i < s.size() - 1;i++) {
		if(s[i] == '-') {
			continue;
		}
		//num = num * 10 + (s[i] - '0');
		buf += (s[i] - '0') * j;
		j++;
	}
	if(s[s.size() - 1] == 'X') {
		if(buf % 11 != 10) {
			cout << s.substr(0,s.size() - 1) << buf % 11;
		}
		else {
			cout << "Right";
		}
	}
	else {
		if(buf % 11 != s[s.size() - 1] - '0') {
			if(buf % 11 == 10) {
				cout << s.substr(0,s.size() - 1) << 'X';
			}
			else {
				cout << s.substr(0,s.size() - 1) << buf % 11;
			}
		}
		else {
			cout << "Right";
		}
	}
	return 0;
}
