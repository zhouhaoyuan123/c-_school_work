#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t --) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ans = 0;
		for(int i = 0;i<s.size();i++) {
			if(s[i] == '0') {
				ans += 1;
			}
			else {
				ans += (n - 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
