#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
long long calc(int x,int y,int x2,int y2) {
	return 1ll * (x2 - x) * (x2 - x) + 1ll * (y2 - y) * (y2 - y);
}
int xnum[2005],ynum[2005];
unordered_map<long long,int> cnt;
set<pair<int,int> > points;

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>xnum[i]>>ynum[i];
		points.insert({xnum[i],ynum[i]});
	}
	long long ans = 0,ans2 = 0;
	for(int i = 1;i<=n;i++) {
		cnt.clear();
		for(int j = 1;j<=n;j++) {
			if(i == j) continue;
			cnt[calc(xnum[i],ynum[i],xnum[j],ynum[j])] ++;
			if(points.count({2 * xnum[i] - xnum[j],2 * ynum[i] - ynum[j]})) {
				ans2 ++;
			}
		}
		for(auto cur : cnt) {
			ans += cur.second * (cur.second - 1) / 2;
		}
	}
	cout << ans - ans2 / 2 << endl;
	return 0;
}
