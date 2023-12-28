#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int BFS(int s,int t) {
	if(s > t) {
		return BFS(t,s);
	}
	int dis[(t - s + 1) * 2];
	memset(dis,-1,sizeof(dis));
	dis[s - s + 1] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(now == t) {
			return dis[now - s + 1];
		}
		if(dis[now + 1 - s + 1] == -1) {
			dis[now + 1 - s + 1] = dis[now - s + 1] + 1;
			q.push(now+1);
		}
		if(now > 0 && dis[now - 1 - s + 1] == -1) {
			dis[now - 1 - s + 1] = dis[now - s + 1] + 1;q.push(now - 1);
		}
		if(now < t && dis[now * 2 - s + 1] == -1) {
			dis[now * 2 - s + 1] = dis[now -s + 1] + 1;q.push(now * 2);
		}
		//if(now > 0 && now % 2 == 0 && dis[now / 2] == -1) {
		//  dis[now / 2] = dis[now] + 1;q.push(now / 2);
		//}
	}    
	return -1;
}

int main() {
//	freopen("dora.in","r",stdin);
//	freopen("dora.out","w",stdout);
	int n;cin>>n;
	while(n --) {
		int s,t;cin>>s>>t;
		cout << BFS(s,t) * 2 << endl; 
	}
	return 0;
}
