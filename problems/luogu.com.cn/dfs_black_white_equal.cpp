#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector <int> G[4005];
bool color[4005];
int black[4005];
int white[4005];
int n;
void dfs(int u) {
	if(color[u]) {
		white[u] ++;
	}
	else {
		black[u] ++;
	}
	for(int i = 0;i<G[u].size();i++) {
		dfs(G[u][i]);
		white[u] += white[G[u][i]];
		black[u] += black[G[u][i]];
	}
}

int main() {
	int t;
	cin>>t;
	while(t --) {
		cin>>n;
		memset(color,0,sizeof(color));
		memset(black,0,sizeof(black));
		memset(white,0,sizeof(white));
		for(int i = 1;i<=n;i++) {
			G[i].clear();
		}
		for(int i = 2;i<=n;i++) {
			int v;
			cin>>v;
			G[v].push_back(i);
		}
		for(int i = 1;i<=n;i++) {
			char tmp;
			cin>>tmp;
			if(tmp == 'B') {
				color[i] = 0;
			}
			else {
				color[i] = 1;
			}
		}
		dfs(1);
		int ans = 0;
		for(int i = 1;i<=n;i++) {
			if(black[i] == white[i]) {
				ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
