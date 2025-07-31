#include <iostream>
#include <cstring>
using namespace std;
long long floyd[505][505];
bool airplane[505];
long long air[505];

int main() {
	memset(floyd,0x3f,sizeof(floyd));
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) floyd[i][i] = 0;
	for(int i = 1;i<=m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		floyd[a][b] = min(floyd[a][b],1ll * c);
		floyd[b][a] = min(floyd[b][a],1ll * c);
	}
	int k,t;
	cin>>k>>t;
	for(int i = 1;i<=k;i++) {
		int x;
		cin>>x;
		airplane[x] = 1;
	}
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=n;j++) {
				if(i != j) {
					floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
				}
			}
		}
	int Q;
	cin>>Q;
	while(Q --) {
		int op;
		cin>>op;
		if(op == 1) {
			int x,y,t;
			cin>>x>>y>>t;
			for(int i = 1;i<=n;i++) {
				for(int j = 1;j<=n;j++) {
					if(i == j) continue;
					floyd[i][j] = min(floyd[i][j],floyd[i][x]+floyd[y][j]+t);
					floyd[i][j] = min(floyd[i][j],floyd[i][y]+floyd[x][j]+t);
				}
			}
		}
		else if(op == 2) {
			int x;
			cin>>x;
			airplane[x] = 1;
		}
		else {
			memset(air,0x3f,sizeof(air));
			for(int i = 1;i<=n;i++) {
				for(int j = 1;j<=n;j++) {
					if(airplane[j]) {
						air[i] = min(air[i],floyd[i][j]);
					}
				}
			}
			long long sum = 0;
			for(int i = 1;i<=n;i++) {
				for(int j = 1;j<=n;j++) {
					long long res = min(floyd[i][j],air[i] + t + air[j]);
					if(res >= 1e18) {
						continue;
					}
					if(i != j) sum += res;
				}
			}
			cout << sum << "\n";
		}
	}
	cout << endl;
	return 0;
}
