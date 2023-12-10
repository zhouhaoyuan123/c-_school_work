#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n,f,m;
	cin>>n>>f>>m;
	int G[n + 1][n + 1];
	int likef[f];
	memset(G,0x3f,sizeof(G));
	for(int i = 0;i<f;i++) {
		cin>>likef[i];
	}
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
	double minn = 1e9;int index = 0;
	for(int i = 1;i<=n;i++) {
		double tmps = 0;
		for(int j = 0;j<f;j++) {
			tmps += G[i][likef[j]];
		}
		tmps /= f;
		if(tmps < minn) {
			index = i;
			minn = tmps;
		}
	}
	cout << index;
	return 0;
}
