#include <iostream>
#include <vector>
using namespace std;
bool vis[200005],vis2[200005];
vector<int> row[200005];
vector<int> col[200005];

int main() {
	int h,w,n;
	cin>>h>>w>>n;
	for(int i = 1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		row[x].push_back(y);
		col[y].push_back(x);
	}
	int q;
	cin>>q;
	while(q --) {
		int op;
		cin>>op;
		if(op == 1) {
			int x;
			cin>>x;
			int tmp = 0;
			if(vis[x]) {
				cout << 0 << endl;
				continue;
			}
			for(int i = 0;i<row[x].size();i++) {
				if(!vis2[row[x][i]]) {
					tmp++;
				}
			}
			cout << tmp << endl;
			vis[x] = 1;
		}
		else {
			int x;
			cin>>x;
			int tmp = 0;
			if(vis2[x]) {
				cout << 0 << endl;
				continue;
			}
			for(int i = 0;i<col[x].size();i++) {
				if(!vis[col[x][i]]) {
					tmp++;
				}
			}
			cout << tmp << endl;
			vis2[x] = 1;
		}
	}
	return 0;
}
