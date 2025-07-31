#include <bits/stdc++.h>
using namespace std;
#define ll long long
char solve(string & s, ll len, ll num) {
	if(num <= s.size()) return s[num - 1];
	if(num <= len / 2) return solve(s,len/2,num);
	if(num == len/2 + 1) return solve(s,len/2,len/2);
	return solve(s,len/2,num - len/2 - 1);
}

int main() {
	string s;
	cin>>s;
	long long k;
	cin>>k;
	long long len = s.size();
	while(len < k) {
		len *= 2;
	}
	cout << solve(s,len,k) << endl;
	return 0;
}
