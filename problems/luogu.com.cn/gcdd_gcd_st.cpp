#include <iostream>
#include <algorithm>
using namespace std;
int num[200005];
int lg[200005];
int st[200005][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 2;i<=200000;i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for(int i = 1;i<=n;i++) {
		cin>>st[i][0];
	}
	for(int j = 1;j<20;j++) {
		for(int i = 1;(1 << j) + i - 1<=n;i++) {
			st[i][j] = __gcd(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
		}
	}
	for(int i = 1;i <= m;i++) {
		int l,r;cin>>l>>r;
		cout << __gcd(st[l][lg[r - l + 1]],st[r - (1 << (lg[r - l + 1])) + 1][lg[r - l + 1]]) << "\n";
	}
	cout << endl;
	return 0;
}
