#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
int n,m,k;
struct city {
	int id;
	int key;
	int step;
};
map<int,long long> keys;
map<int,map<int,long long> > need;
map<long long,map<int , bool> > vis;
//钥匙 ， 城市是否访问问
int bfs() {
	queue<city> q;
	vis[keys[1]][1] = true;
	q.push({1,keys[1],0});
	while(!q.empty()) {
		city now2 = q.front();
		q.pop();
		if(now2.id == n) {
			return now2.step;
		}
		city now = now2;
		for(auto & it : need[now2.id]) {//循环入
			//cout << now.key<<endl;
			//if(need[now.id][i] <= now.key) cout << "ok"<<endl;
			if(it.second <= now.key) {
				if(!vis[now.key][it.first]) {
					vis[now.key][it.first] = true;
					now.id = it.first;
					now.key |= keys[it.first];
					now.step++;
					q.push(now);
				}
			}
			now = now2;
		}
	}
	return -1;
}

int main() {
//	freopen("task.in","r",stdin);freopen("task.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) {
		int buf = 0;
		int p = k-1;
		for(int j = 1;j<=k;j++) {
			int tmp;
			cin>>tmp;
			buf += tmp * pow(2,p);
			p--;
		}
		keys[i] = buf;
	}
	for(int i = 0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		int buf = 0;
		int p = k-1;
		for(int j = 1;j<=k;j++) {
			int tmp;
			cin>>tmp;
			buf += tmp * pow(2,p);
			p--;
		}
		if(!need[u].count(v)) {
			need[u][v] = buf;
			continue;
		}
		need[u][v] = min(int(need[u][v]),buf);
	}
	int tmp = bfs();
	if(tmp == -1) cout << "No Solution";
	else cout << tmp;
	return 0;
}
