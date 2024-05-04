#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstdio>
using namespace std;
pair<int,int> height[50005];
pair<int,int> q[50005];
bool vis[10000005];
int ans[50005];
bool cmp(pair<int,int> x,pair<int,int> y) {
	return x.first < y.first;
}

int main() {
//	freopen("forest.in","r",stdin);
//	freopen("forest.out","w",stdout);
	int n,qn;
	cin>>n>>qn;
	for(int i = 1;i<=n;i++) {
		cin>>height[i].first;
		height[i].second = i;
	}
	sort(height+1,height+n+1,cmp);
	for(int i = 1;i<=qn;i++) {
		cin>>q[i].first;
		q[i].second = i;
	}
	sort(q+1,q+qn+1,cmp);
	int tot = n;
	for(int i = qn;i>=1;i--) {
		ans[q[i].second] = ans[q[i + 1].second];
		while(tot > 0 && height[tot].first > q[i].first) {
			if(vis[height[tot].second - 1] && vis[height[tot].second + 1]) 
				ans[q[i].second] --;
			else if(!vis[height[tot].second - 1] && !vis[height[tot].second + 1])
				ans[q[i].second] ++;
			vis[height[tot].second] = true;
			//cout << ans[i]<<" ";
			tot--;
		}
		//cout << endl;
	}
	for(int i = 1;i<=qn;i++) {
		cout << ans[i]<<endl;
	}
	return 0;
}
