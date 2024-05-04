#include <iostream>
#include <algorithm>
using namespace std;
int vis[1000005];
int a[20005],b[20005],c[1000005],n,m = 0;
int query(int v)
{
	int l = 1, r = m;
	while(l <= r)
	{
		int mid = (l+r) / 2;
		if (v > c[mid]) l = mid + 1;
		else if(v < c[mid]) r = mid - 1;
		else return mid;
	}
	return -1;
}

int main() {
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>a[i]>>b[i];
		c[++m] = a[i];
		c[++m] = b[i];
	}
	sort(c+1,c+1+m);
	int ans = 0;
	m = unique(c+1,c+1+m) - c;
	for(int i = 1;i<=n;i++) {
		int l = query(a[i]);
		int r = query(b[i]);
		vis[l] += 1;
		vis[r] -= 1;
	}
	int cnt = vis[1];
	for(int i = 2;i<=m;i++) { 
		if(cnt) {
			ans += c[i] - c[i - 1];
		}
		cnt += vis[i];
	}
	cout << ans;
	return 0;
}
