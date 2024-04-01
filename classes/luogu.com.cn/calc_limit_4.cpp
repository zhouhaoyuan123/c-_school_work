#include <iostream>
#include <sstream>
using namespace std;
long long calc(string s) {
	int cnt = 0;
//	if(s.size() == 1 && s[0] >= '0' && s[0] <= '9') {
//		return s[0] - '0';
//	}
	bool flag = false,flag2 = true;
	for(int i = 0;i<s.size();i++) {
		if(s[i] == '(') {
			cnt++;
		}
		if(s[i] == ')') {
			cnt --;
		}
		if(cnt == 0 && i != s.size() - 1) {
			flag = true;
		}
		if(!(s[i] >= '0' && s[i] <= '9')) {
			flag2 = false;
		}
	}
	if(flag2) {
		stringstream ss;
		ss<<s;
		long long tmp;
		ss>>tmp;
		return tmp % 10000;
	}
	if(!flag) {
		s.replace(0,1,"");
		s.replace(s.size() - 1,1,"");
	}
	for(int i = 0;i<s.size();i++) {
		if(s[i] == '(') {
			cnt++;
		}
		if(s[i] == ')') {
			cnt --;
		}
		if(cnt == 0) {
			if(s[i] == '+') {
				return (calc(s.substr(0,i)) % 10000 + calc(s.substr(i + 1,s.size() - i - 1)) % 10000) % 10000;
			}
		}
	}
	for(int i = 0;i<s.size();i++) {
		if(s[i] == '(') {
			cnt++;
		}
		if(s[i] == ')') {
			cnt --;
		}
		if(cnt == 0) {
			if(s[i] == '*') {
				return calc(s.substr(0,i)) % 10000 * (calc(s.substr(i + 1,s.size() - i - 1)) % 10000) % 10000;
			}
		}
	}
	return -1;
}

int main() {
	string s;
	cin>>s;
	cout << calc(s);
}
