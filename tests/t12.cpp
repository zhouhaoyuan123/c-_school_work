#include<bits/stdc++.h>
using namespace std;
int n, r[100010];
pair<int,int> zone[100010];
int main() {
	string s = "$#", a;
	cin >> a;
	for(int i = 0;i<a.size();i++) {
		s += a[i];
		s += "#";
	}
	s += "^";
	for(int i = 1,mx = 0,id = 0;i + 1 < s.size();i ++) {
		if(i <= mx) r[i] = min(mx - i,r[2 * id - i]); 
		while(s[i - r[i]] == s[i + r[i]]) {r[i] ++;}
		r[i] --;
		if(i + r[i] > mx) {
			mx = i + r[i];
			id = i;
		} 
		zone[i].first = i - r[i];
		zone[i].second = i + r[i];
	}
	sort(zone + 1,zone + 1 + (s.size() - 2));
	int r = 0;
	int i = 1;
	int ans = 0;
	while(i <= s.size() - 2) {
		bool flag = false;
		while(i <= s.size() - 2 && zone[i].first <= r + 1) {
			i ++;
			flag = true;
		}
		if(flag) i --;
		ans ++;
		r = zone[i].second;
		cout << i << endl;
	} 
	cout << ans << endl;
	return 0;
}
