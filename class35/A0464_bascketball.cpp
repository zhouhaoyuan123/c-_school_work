#include <iostream>
using namespace std;
int height[25];
bool vis[25];
int ans = 0;
int n,m,h;
void dfs(int step,int cnt,int num) {
	if(step == n) {
		if(1.0 * cnt / m  >= 1.0 * h && num == m) {
			ans++;
		}
		return;
	}
	vis[step] = 1;
	dfs(step+1,cnt+height[step],num+1);
	vis[step] = 0;
	dfs(step+1,cnt,num);
}

int main() {
	cin>>n>>m>>h;
	for(int i = 0;i<n;i++) {
		cin>>height[i];
	}
	dfs(0,0,0);
	cout << ans;
	return 0;
}
