#include <iostream>
#include <string>
using namespace std;
string change(string before) {
	string ans = before;
	for(int i = 0;i<before.size();i++) {
		if(before[i] == '1') {
			if(i + 1 < before.size()) {
				ans[i + 1] = '1';
			}
			if(i - 1 >= 0) {
				ans[i - 1] = '1';
			}
		}
	}
	return ans;
}

int main() {
	int N;
	cin>>N;
	string s;
	cin>>s;
	int l = 0,r = N - 1;
	while(true) {
		string cows = s;
		if(l > r) {
			break;
		}
		if(l == r) {
			int cnt = 0;
			for(int i = 0;i<N;i++) {
				if(cows[i] - '0') cnt++; 
			}
			cout << cnt;
			return 0;
		}
		cows[l] = '0';
		cows[l+1] = '1';
		cows[r] = '0';
		cows[r - 1] = '1';
		if(change(cows) != s) {
			l = r;
			continue;
		}
		else {s = cows;}
		l++;
		r--;
	}
	return 0;
}
