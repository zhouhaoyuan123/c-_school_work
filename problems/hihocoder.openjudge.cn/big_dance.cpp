#include <iostream>
using namespace std;
int vis[100005];
int nxt[100005];

int main() {
	int N;
	cin>>N;
	for(int i = 1;i<=N;i++) {
		cin>>nxt[i];
	}
	int tot = 0;
	int ans = 0;
	for(int i = 1;i<=N;i++) {
		if(!vis[i]) {
			int cur = i,tmp = tot;
			while(!vis[nxt[cur]]) {
				vis[cur] = ++tot;
				cur = nxt[cur];
			}
			if(vis[nxt[cur]] > tmp) {
				vis[cur] = ++tot;
				ans += vis[cur] - vis[nxt[cur]] + 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
