#include<iostream>
#include <cstring>
using namespace std;
int G[101][101];bool vis[101];
int n,m;
bool flag;
void dfs(int i,int s) {
	vis[i] = true;
	if(s<= 1) {
		flag = true;
		return;
	}
	for(int j = 1;j<=n;j++) {
		if(G[i][j] && !vis[j]) {
			dfs(j,s - 1);
			vis[j] = false;
		}
	}
}

int main() {
	cin>>n>>m;
	for(int i = 0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	for(int i = 1;i<=n;i++) {
		memset(vis,0,sizeof(vis));
		dfs(i,n);
		if(!flag) {
			cout << "no";
			return 0;
		}
		flag = false;
	}
	cout << "yes";
	return 0;
}
