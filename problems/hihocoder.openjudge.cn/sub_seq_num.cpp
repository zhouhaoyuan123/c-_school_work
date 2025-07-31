#include <iostream>
using namespace std;
int num[30];

int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt = 0;
	long long ans = 0;
	for(int r = 0,l = 0;l<n;l++) {
		if(l > 0) {
			if(--num[s[l - 1] - 'A'] == 0) cnt --;
		}
		while(cnt <= 2 && r < n) {
			if(++num[s[r] - 'A'] == 1) cnt ++;
			r ++;
		}
		if(cnt > 2) {
			--num[s[r - 1] - 'A'];
			cnt --;
			r --;
		}
		ans += r - l;
	}
	cout << ans << "\n";
	return 0;
}
