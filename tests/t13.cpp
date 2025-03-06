#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
const int maxn = 100005;
int n, m;
string a;
int f[maxn][25], l, r;
int Log2[maxn];
void prepare() {
	cin >> a;
	a += " ";
	n = a.size();
	for (int i = 2; i <= n; i++) {
		Log2[i] = Log2[i / 2] + 1;  // 也可以直接用 log2(i) 完成计算
	}
	for(int i = 1;i<=n;i++) {
		f[i][0] = i - 1;
	}
	for(int j = 1;(1 << j) <= n;j++) {
		for(int i = 1;i + (1 << j) - 1<= n;i++) {
			if(a[f[i][j - 1]] < a[f[i + (1 << (j - 1))][j - 1]]) {
				f[i][j] = f[i][j - 1];
			}
			else {
				f[i][j] = f[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}
int query(int l, int r) {
	int i = Log2[r - l + 1];
	if(a[f[l][i]] < a[f[r - (1 << i) + 1][i]]) {
		return f[l][i];
	}
	else {
		return f[r - (1 << i) + 1][i];
	}
}
int main() {
	prepare();
	cin>>m;
	int index = 0;
	string ans = "";
	while(m) {
		int tmp = index;
		index = query(index + 1,min(index + m + 1,n));
		ans += a[index];
		m -= (index - tmp);
		if(index < a.size() - 1)
			index ++;
	}
	if(index < a.size() - 1) {
		for(int i = index;i<a.size();i++) {
			ans += a[i];
		}
	}
	int i = 0;
	if(ans[ans.size() - 1] == ' ') {
		ans = ans.substr(0,ans.size() - 1);
	}
	while(i < ans.size() && ans[i] == '0') {
		i++;
	}
	if(i >= ans.size()) cout << 0 << endl;
	else cout << ans.substr(i) << endl;
	return 0;
}

