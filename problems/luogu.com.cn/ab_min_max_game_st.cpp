#include <iostream>
#include <climits>
using namespace std;
long long num[100005];
long long lg[100005];
long long st[100005][20];
long long st2[100005][20];//min max
long long st3[100005][20];
long long st4[100005][20];
long long st5[100005][20];
long long st6[100005][20];//positive negative
long long query(long long st[][20],int l,int r) {
	return min(st[l][lg[r - l + 1]],st[r - (1 << (lg[r - l + 1])) + 1][lg[r - l + 1]]);
}
long long query2(long long st[][20],int l,int r) {
	return max(st[l][lg[r - l + 1]],st[r - (1 << (lg[r - l + 1])) + 1][lg[r - l + 1]]);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i = 2;i<=100000;i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for(int i = 1;i<=n;i++) {
		cin>>st[i][0];
		st2[i][0] = st[i][0];
		if(st[i][0] >= 0) {
			st3[i][0] = st[i][0];
			st4[i][0] = LONG_LONG_MIN;
		}
		else {
			st3[i][0] = LONG_LONG_MAX;
			st4[i][0] = st[i][0];
		}
	}
	for(int i = 1;i<=m;i++) {
		cin>>st5[i][0];
		st6[i][0] = st5[i][0];
	}
	for(int j = 1;j<20;j++) {
		for(int i = 1;(1 << j) + i - 1<=n;i++) {
			st[i][j] = max(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
			st2[i][j] = min(st2[i][j - 1],st2[i + (1 << (j - 1))][j - 1]);
			st3[i][j] = min(st3[i][j - 1],st3[i + (1 << (j - 1))][j - 1]);
			st4[i][j] = max(st4[i][j - 1],st4[i + (1 << (j - 1))][j - 1]);
			st5[i][j] = min(st5[i][j - 1],st5[i + (1 << (j - 1))][j - 1]);
			st6[i][j] = max(st6[i][j - 1],st6[i + (1 << (j - 1))][j - 1]);
		}
	}
	while(q --) {
		int l,r,l2,r2;
		cin>>l>>r>>l2>>r2;
		//min(st[l][lg[r - l + 1]],st[r - (1 << (lg[r - l + 1])) + 1][lg[r - l + 1]])
		long long a = query2(st,l,r);
		long long b = query(st2,l,r);
		long long c = query(st3,l,r);
		long long d = query2(st4,l,r);
		long long e = query(st5,l2,r2);
		long long f = query2(st6,l2,r2);
		long long ans = LONG_LONG_MIN;
		ans = max(ans,a * (a >= 0 ? e : f));
		ans = max(ans,b * (b >= 0 ? e : f));
		if(c < LONG_LONG_MAX) {
			ans = max(ans,c * (c >= 0 ? e : f));
		}
		if(d > LONG_LONG_MIN) {
			ans = max(ans,d * (d >= 0 ? e : f));
		}
		cout << ans << "\n";
	}
	cout << endl;
	return 0;
}
