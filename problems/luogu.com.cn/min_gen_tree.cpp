#include <iostream>
#include <queue>
using namespace std;
#define N 200005
int father[N];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
int find(int u) {
	if(u == father[u]) return u;
	return father[u] = find(father[u]);
}
void merge(int x,int y) {
	father[find(x)] = find(y);
}
void init(int x) {
	for(int i = 1;i<=x;i++) {
		father[i] = i;
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	init(n);
	for(int i = 1;i<=m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		q.push({z,{x,y}});
	}
	if(m < n - 1) {
		cout << "orz" << endl;
		return 0;
	}
	int tmp = n - 1;
	int ans = 0;
	while(!q.empty() && tmp) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int z = q.top().first;
		q.pop();
		if(find(x) != find(y)) {
			ans += z;
			merge(x,y);
			tmp --;
		}
	}
	int tmp2 = 0;
	for(int i = 1;i<=n;i++) {
		if(find(i) == i) tmp2 ++;
	}
	if(tmp2 > 1) {
		cout << "orz" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
