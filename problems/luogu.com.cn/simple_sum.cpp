#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin>>s;
	long long ans = 0;
	long long buf = 0;
	//bool flag = 0;
	for(int i = 0;i<s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			buf = buf * 10 + s[i] - '0';
			//buf %= 100000;
		}
		else if(s[i] == '*') {
			long long buf2 = 1;
			for(;i<s.size();i++) {
				if(s[i] >= '0' && s[i] <= '9') {
					buf2 = buf2 * 10 + s[i] - '0';
					//buf2 %= 100000;
				}
				else if(s[i] == '*') {
					buf = (buf % 100000) * (buf2 % 100000);
					buf %= 100000;
					buf2 = 0;
				}
				else if(s[i] == '+') {
					if(buf2 > 0) {
						buf = (buf % 100000) * (buf2 % 100000);
					}
					ans = (ans % 100000) + buf % 100000;
					ans %= 100000;
					buf = 0;
					buf2 = 0;
					break;
				}
			}
			if(buf2 > 0) {
				buf = (buf % 100000) * (buf2 % 100000);
				//buf %= 10000;
				buf2 = 0;
				ans = (ans % 100000) + buf % 100000;
				ans %= 100000;
				buf = 0;
			}
		}
		else if(s[i] == '+'){
			ans = (ans % 100000) + buf % 100000;
			ans %= 100000;
			buf = 0;
		}
	}
	if(buf > 0 ) {
		ans = (ans % 100000) + buf % 100000;
		ans %= 100000;
	}
	cout << ans % 10000;
	return 0;
}
