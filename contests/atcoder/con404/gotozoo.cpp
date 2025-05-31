#include <iostream>
#include <map>
using namespace std;
int n,m;
int k[105];
int c[15];
bool G[15][105];
int vis[15];
map<string,long long> res;
string num = "";
long long dfs(int id,long long cnt) {
	bool flag = 1;
	for(int i = 1;i<=m;i++) {
		if(num[i] < '2') {
			flag = 0;
			break;
		}
	}	
	if(flag) {
		return cnt;
	}
	if(id > n) return 1e12;
	long long ans = 1e12;
	int i = id;
	ans = min(ans,dfs(id + 1,cnt));
	if(vis[i] < 2) {
		for(int j = 1;j<=m;j++) {
			if(G[i][j]) {
				num[j] ++;
			}
		}
		vis[i] ++;
		ans = min(ans,dfs(id,cnt + c[i]));
		vis[i] --;
		for(int j = 1;j<=m;j++) {
			if(G[i][j]) {
				num[j] --;
			}
		}
	}
	return ans;
}

int main() {
	cin>>n>>m;
	num+="0";
	for(int i = 1;i<=m;i++) num += "0";
	for(int i = 1;i<=n;i++) {
		cin>>c[i];
	}
	for(int i = 1;i<=m;i++) {
		cin>>k[i];
		for(int j = 1;j<=k[i];j++) {
			int x;
			cin>>x;
			G[x][i] = 1;
		}
	}
	cout<<dfs(1,0)<<endl;
	return 0;
}
