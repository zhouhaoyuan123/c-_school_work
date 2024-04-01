#include <iostream>
#include <queue>
using namespace std;
bool vis[1005];

int main() {
	queue<int> q;
	int n,m;
	cin>>n>>m;
	int ans = 0;
	for(int i = 1;i<=m;i++) {
		int op;
		cin>>op;
		if(!vis[op]) {
			vis[op] = 1;
			q.push(op);
			if(q.size() > n) {
				vis[q.front()] = 0;
				q.pop();
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}
