#include <iostream>
using namespace std;
int num[100005];
int lg[100005];
int st[100005][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 2;i<=100000;i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for(int i = 1;i<=n;i++) {
		cin>>st[i][0];
	}
	for(int j = 1;j<20;j++) {
		for(int i = 1;(1 << j) + i - 1<=n;i++) {
			st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
		}
	}
	for(int i = 1;i <= n - m + 1;i++) {
		int l = i,r = i + m - 1;
		cout << min(st[l][lg[r - l + 1]],st[r - (1 << (lg[r - l + 1])) + 1][lg[r - l + 1]]) << "\n";
	}
	cout << endl;
	return 0;
}
