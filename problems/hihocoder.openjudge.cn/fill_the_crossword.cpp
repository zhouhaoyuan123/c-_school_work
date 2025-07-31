#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string eight[7];
string eight2[7];
bool judge() {
	if(eight[4].size() != eight[1].size() + eight[6].size() - 1) return false;
	if(eight[3].size() != eight[2].size() + eight[5].size() - 1) return false;
	if(eight[1].front() != eight[2].front()) return false;
	if(eight[1].back() != eight[3].front()) return false;
	if(eight[2].back() != eight[4].front()) return false;
	if(eight[4][eight[1].size() - 1] != eight[3][eight[2].size() - 1]) return false;
	if(eight[3].back() != eight[6].front()) return false;
	if(eight[6].back() != eight[5].back()) return false;
	if(eight[4].back() != eight[5].front()) return false;
	return true;
}
string convert(int & n,int & m) {
	n = eight[3].size();
	m = eight[4].size();
	string ans = "";
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			ans += ".";
		}
	}
	for(int i = 0;i<eight[1].size();i++) {
		ans[i] = eight[1][i];
	} 
	for(int i = 0;i<eight[4].size();i++) {
		ans[i + (eight[2].size() - 2) * m] = eight[4][i];
	}
	for(int i = 0;i<eight[6].size();i++) {
		ans[i + (eight[3].size() - 2) * m + eight[1].size() - 1] = eight[6][i];
	}
	for(int i = 0,j = 0;i<eight[2].size();i++,j+=m) {
		ans[j] = eight[2][i];
	}
	for(int i = 0,j = eight[1].size() - 1;i<eight[3].size();i++,j+=m) {
		ans[j] = eight[3][i];
	}
	for(int i = 0,j = eight[4].size() - 1;i<eight[5].size();i++,j+=m) {
		ans[j] = eight[5][i];
	}
	return ans;
}

int main() {
	for(int i = 1;i<=6;i++) {
		cin>>eight[i];
		eight2[i - 1] = eight[i];
	}
	string ans = "a";
	int ansn = 1,ansm = 1;
	for(int i = 0;i<720;i++) {
		next_permutation(eight2,eight2+6);
		for(int i = 0;i<6;i++) {
			eight[i + 1] = eight2[i];
		}
		if(judge()) {
			int n,m;
			string tmp = convert(n,m);
			if(tmp < ans) {
				ans = tmp;
				ansn = n;
				ansm = m;
			}
		}
	}
	for(int i = 0;i<ans.size();i++) {
		cout << ans[i];
		if(i % ansm == ansm - 1) cout << endl;
	}
	return 0;
}
