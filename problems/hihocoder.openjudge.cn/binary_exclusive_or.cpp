#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans = "";
	if(a.size() > b.size()) {
		ans = a;
	}
	else {
		ans = b;
	}
	for(int i = 0;i<min(a.size(),b.size());i++) {
		if(a[i] == b[i]) {
			ans[i] = '0';
		}
		else {
			ans[i] = '1';
		}
	}
	reverse(ans.begin(),ans.end());
	for(;ans[0] == '0' && ans.size() > 1;) {
		ans.replace(0,1,"");
	}
	cout << ans << endl;
	return 0;
}
