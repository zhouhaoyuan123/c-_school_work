#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10;
int nxt[maxn],ans[maxn],cow[maxn];
set<int> cnt[maxn];
int a[maxn],b[maxn];
vector<int> seq[maxn];

int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=k;i++) cin>>a[i]>>b[i];
	for(int i = 1;i<=n;i++) {
		cow[i] = i;
		seq[i].push_back(i);
	}
	for(int i = 1;i<=k;i++) {
		swap(cow[a[i]],cow[b[i]]);
		seq[cow[a[i]]].push_back(a[i]);
		seq[cow[b[i]]].push_back(b[i]);
	}
	for(int i = 1;i<=n;i++) nxt[i] = seq[i].back();
	for(int i = 1;i<=n;i++) {
		if(ans[i]) continue;
		int cur = i;
		while(true) {
			ans[cur] = i;
			for(int tmp : seq[cur]) cnt[i].insert(tmp);
			cur = nxt[cur];
			if(cur == i) break;
		}
	}
	for(int i = 1;i<=n;i++) cout << cnt[ans[i]].size() << "\n";
	cout << endl;
	return 0;
}
