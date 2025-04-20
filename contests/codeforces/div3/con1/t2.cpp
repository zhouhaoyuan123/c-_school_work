#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int zeroes[105];

int main() {
	int t;
	cin>>t;
	while(t --) {
		memset(zeroes,0,sizeof(zeroes));
		string s;
		cin>>s;
		int n = s.size();
		for(int i = 0;i<s.size();i++) {
			if(s[i] == '0') {
				zeroes[i + 1] = zeroes[i] + 1;
			}
			else if(i != 0 && s[i - 1] == '0') {
				zeroes[i + 1] = zeroes[i];
			}
			else {
				zeroes[i + 1] = 0;
			}
		}
		int ans = s.size() - 1;
		for(int i = 1;i<=s.size();i++) {
			if(s[i - 1] != '0')
				ans = min(ans, n - 1 - zeroes[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
