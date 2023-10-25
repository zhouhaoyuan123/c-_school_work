#include <iostream>
#include <cstring>
using namespace std;
int G[101][101];
int n,m,s;
int dis[101];bool vis[101];bool flag = false;
const int inf = 1e6;
void djsktra() {
	int min = inf;
	int dism = inf;
	for(int i = 1;i<=n;i++) {
		if(dism > dis[i] && vis[i] == 0) {
			min = i;
			dism = dis[i];
		}
	}
	if(dism == inf) {
		flag = true;
		return;
	}
	vis[min] = 1;
	for(int i = 1;i<=n;i++) {
		if(G[min][i]) {
			if(dis[i] > dism + G[min][i]) {
				dis[i] = dism;
			}
		}
	}
}

int main() {
	cin>>n>>m>>s;
//	memset(G,inf,sizeof(G));
//	memset(dis,inf,sizeof(dis));
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(i == s) {
				dis[j] = inf;
			}
			G[i][j] = inf;
		}
	}
	for(int i = 1;i<=m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		if(x == s) {
			dis[y] = z;
		}
		if(y == s) {
			dis[x] = z;
		}
		G[x][y] = z;
		G[y][x] = z;
	}
	while(!flag) {
		djsktra();
	}
	for(int i = 1;i<=n;i++) {
		if(dis[i] == inf) {
			cout << "INF ";
		}
		cout << dis[i]<<" ";
	}
}
