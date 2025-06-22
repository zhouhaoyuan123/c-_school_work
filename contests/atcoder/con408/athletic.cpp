#include <iostream>
#include <algorithm>
using namespace std;
int nodes[20000005];
int dp[500005];
pair<int,int> num[500005];
void update(int id,int l,int r,int tl,int tr,int target) {
	if(l == r) {
		nodes[id] = target;
		return;
	}
	int mid = (l + r) / 2;
	if(tr <= mid) {
		update(id * 2,l,mid,tl,tr,target);
	}
	else if(tl > mid) {
		update(id * 2 + 1,mid + 1,r,tl,tr,target);
	}
	else {
		update(id * 2,l,mid,tl,mid,target);
		update(id * 2 + 1,mid + 1,r,mid + 1,tr,target);
	}
	nodes[id] = max(nodes[id * 2],nodes[id * 2 + 1]);
}
int query(int id,int l,int r,int tl,int tr) {
	if(l == r) {
		return nodes[id];
	}
	int mid = (l + r) / 2;
	if(tr <= mid) {
		return query(id * 2,l,mid,tl,tr);
	}
	else if(tl > mid) {
		return query(id * 2 + 1,mid + 1,r,tl,tr);
	}
	else {
		return max(query(id * 2,l,mid,tl,tr),query(id * 2 + 1,mid + 1,r,tl,tr));
	}
}

int main() {
	int n,d,r;
	cin>>n>>d>>r;
	for(int i = 1;i<=n;i++) {
		int x;
		cin>>x;
		num[i] = {x,i};
	}
	sort(num+1,num+1+n);
	for(int i = 2;i<=n;i++) {
		//lower_bound(num+1,num+1+i,make_pair(num[i].first - d,i)) - num
		int tmp = lower_bound(num+1,num+1+i,make_pair(num[i].first - d,i)) - num;
		if(tmp > 0) {
			tmp = num[tmp].second;
			dp[i] = query(1,1,n,max(1 * i - r,1),tmp) + 1;
		}
		update(1,1,n,num[i].second,num[i].second,dp[i]);
	}
	
	return 0;
}
