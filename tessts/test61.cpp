#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
struct point {
	int id;
	int step;
};
vector<int> G[1000005];
int ans[1000005];
int steps[1000005];

int main() {
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int N,M;
	cin>>N>>M;
	for(int i = 0;i<M;i++) {
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	queue<point> q;
	q.push({1,0});
	while(!q.empty()) {
		point now = q.front();
		q.pop();
		for(int i = 0;i<G[now.id].size();i++) {
			if(G[now.id][i] == now.id) continue;
			if(steps[G[now.id][i]] == 0 || steps[G[now.id][i]] == now.step+1) {
				steps[G[now.id][i]] = now.step+1;
				ans[G[now.id][i]] ++;
				ans[G[now.id][i]] %= 1000003;
				q.push({G[now.id][i],now.step+1});
			}
		}
	}
	for(int i = 1;i<=N;i++) cout << ans[i] << endl;
	return 0;
}
