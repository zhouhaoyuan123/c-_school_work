#include <iostream>
#include <algorithm>
using namespace std;
struct line {
	int l,r;
}lines[1000005];
bool vis[1000005];
int area[1000005];
bool cmp(line x,line y) {
	return x.r < y.r;
}

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>lines[i].l >> lines[i].r;
	}
	int ans = 0;
	area[0] = n;
	sort(lines+1,lines+1+n,cmp);
	int j = 0;
	for(int i = 1;i<=n;i++) {
		if(j == 0) {
			j = i;
			ans++;
		}
		else {
			if(lines[i].l >= lines[j].r) {
				ans++;
				j = i;
			}
		}
	}
	cout << ans;
	return 0;
}
