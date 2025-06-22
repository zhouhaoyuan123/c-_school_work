#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
pair<pair<int,int>,long long> edge[200005];
vector<pair<long long,int> > G[200005];
bool vis[200005];

int main() {
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		int x,y,w;
		cin>>x>>y>>w;
		edge[i] = {{x,y},w};
	}
	long long ans = 0;
	long long lim = (1LL << 30) - 1;
	ans = lim;
	for(int i = 29;i>=0;i--) {
		memset(vis,0,sizeof(vis));
		for(int j = 1;j<=n;j++) G[j].clear();
		long long tmp = lim ^ (ans - (1LL << i));
		for(int j = 1;j<=m;j++) {
			if((tmp & edge[j].second) == 0) {
				G[edge[j].first.first].push_back({edge[j].second,edge[j].first.second});
				G[edge[j].first.second].push_back({edge[j].second,edge[j].first.first});
			}
		}
		queue<int> q;
		q.push(1);
		bool flag = 1;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			if(vis[cur]) {continue;}
			vis[cur] = 1;
			if(cur == n) {flag = 0;break;}
			for(int j = 0;j<G[cur].size();j++) {
				q.push(G[cur][j].second);
			}
		}
		if(!flag) {
			ans -= (1LL << i);
		}
	}
	cout << ans << endl;
	return 0;
}
