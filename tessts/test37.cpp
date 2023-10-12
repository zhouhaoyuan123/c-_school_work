#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
//	freopen("p.in","r",stdin);
//	freopen("p.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int p = 0;
		int n;
		cin>>n;
		vector<int> g[n+1];
		int parent[n+1];
		memset(parent,0,sizeof(parent));
		for(int i = 0;i<n;i++) {
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			parent[y] = x;
		}
		for(int i = 1;i<=n;i++) {
			if(g[parent[i]].size() <= g[i].size()) {
				bool flag = 1;
				for(int j = 0;j<g[i].size();j++) {
					if(g[g[i][j]].size() > g[i].size()) {
						cout << "! OK" << " "<<i<<" : " << g[i][j] <<"(" << g[g[i][j]].size() << "," << g[i].size() << ")" << endl;
						flag = 0;
						break;
					}
				}
				if(flag) {
					cout << "OK" << " "<<i<<endl;
					p++;
				}
			}
		}
		cout << p;
	}
	return 0;
}
