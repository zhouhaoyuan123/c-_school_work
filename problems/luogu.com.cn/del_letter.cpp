#include <iostream>
#include <string>
using namespace std;
bool vis[205];

int main() {
	string s;
	cin>>s;
	int k;
	cin>>k;
	int last = 0;
	for(int i = 1;i<s.size();i++) {
		if(vis[i]) {
			continue;
		}
		if(k == 0) {
			break;
		}
		if(s[i] <= s[last]) {
			k --;
			vis[last] = true;
			last = i;
		}
		else {
			int tmp = i;
			for(int j = i+1;j<s.size() && (vis[j] || (s[j] >= s[j - 1]));j++) {
				tmp = j;
			}
			int tmp2 = last;
			last = tmp - k;
			if(last < 0 || vis[last]) {
				last = tmp2;
			}
			for(int j = tmp;j>=i;j--) {
				if(k > 0) {
					vis[j] = true;
					k--;
					//last = j - 1;
				}
				else {
					break;
				}
			}
		}
	}
	for(int i = 0;i<s.size();i++) {
		if(!vis[i]) {
			cout << s[i];
		}
	}
	return 0;
}
