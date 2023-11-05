#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int G[11][11];
vector<int> vec[11];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		G[u][v] = 1;
		G[v][u] = 1;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cout << setw(3) << G[i][j];
		}
		cout << endl;
	}
	for(int i = 1;i<=n;i++) {
		cout << setw(3) << vec[i].size();
		sort(vec[i].begin(),vec[i].end());
		for(auto j = vec[i].begin();j != vec[i].end();j++) {
			cout << setw(3) << *j;
		}
		cout << endl;
	}
	return 0;
}
