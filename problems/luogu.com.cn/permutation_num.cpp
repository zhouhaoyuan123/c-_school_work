#include <iostream>
using namespace std;
long long fac[15];

int main() {
	string s;
	cin>>s;
	fac[0] = 1;
	for(int i = 0;i<s.size();i++) {
		fac[i + 1] = fac[i] * (i + 1);
	}
	long long ans = 0;
	for(int i = 0;i<s.size();i++) {
		int tmp = 0;
		for(int j = 0;j<i;j++) {
			if(s[j] < s[i]) {
				tmp ++;
			}
		}
		ans += (s[i] - 'a' - tmp) * fac[s.size() - i - 1];
	}
	cout << ans << endl;
	return 0;
}
