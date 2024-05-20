#include <iostream>
#include <cstring> 
using namespace std;
int depth = 0,width = 0,ans3 = 0;
int next_num[105],prev_num[105];
int next2[105];
int vis[105];
int cnt[105];
int n;
void dfs(int step,int index) {
	if(index > n) {
		return;
	}
	if(index == -1) {
		return;
	}
	//width = max(width,length);
	vis[index] = step;
	depth = max(depth,step);
	dfs(step+1,next_num[index]);
	dfs(step+1,next2[index]);
}
int ans4 = 0;
void search(int step,int index) {
	if(index == -1) {
		return;
	}
	if(vis[index] != -1) {
		ans4 = vis[index] * 2 + step;
		return;
	}
	vis[index] = step;
	search(step+1,prev_num[index]);
}

int main() {
	//int n;
	cin>>n;
	memset(next_num,-1,sizeof(next_num));
	memset(next2,-1,sizeof(next2));
	memset(prev_num,-1,sizeof(prev_num));
	for(int i = 1;i<=n - 1;i++) {
		int x,y;
		cin>>x>>y;
		if(next_num[x] == -1)
			next_num[x] = y;
		else 
			next2[x] = y;
		prev_num[y] = x;
	}
	int x,y;
	cin>>x>>y;
	dfs(1,1);
	for(int i = 1;i<=n;i++) {
		cnt[vis[i]] ++;
		ans3 = max(ans3,cnt[vis[i]]);
	}
	memset(vis,-1,sizeof(vis));
	cout << depth<<endl<<ans3<<endl;
	search(0,x);
	search(0,y);
	cout << ans4;
	return 0;
}
