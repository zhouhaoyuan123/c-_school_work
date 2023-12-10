#include <iostream>
#include <cstring>
using namespace std;
int G[105][105];

int main() {
	int n,m;
	cin>>n>>m;
	memset(G,0x3f,sizeof(G));
	for(int i = 0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		G[u][v] = w;
		G[v][u] = w;
	}
	for(int i = 1;i<=n;i++) {
		G[i][i] = 0;
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			for(int z = 1;z<=n;z++) {
				G[j][z] = min(G[j][i] + G[i][z],G[j][z]);
			}
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
