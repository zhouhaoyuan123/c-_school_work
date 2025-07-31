#include <iostream>
#include <algorithm>
using namespace std;
long long nodes[400005];
long long mark[400005];
void update(int id,int l,int r,int tl,int tr,long long target) {
	if(l == r) {
		nodes[id] += target;
		return;
	}
	if(l == tl && r == tr) {
		mark[id] += target;
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
	nodes[id] = nodes[id * 2]+nodes[id * 2 + 1];
}
long long query(int id,int l,int r,int tl,int tr) {
	if(l == r) {
		nodes[id] += mark[id];
		mark[id] = 0;
		return nodes[id];
	}
	mark[id * 2] += mark[id];
	mark[id * 2 + 1] += mark[id];
	mark[id] = 0;
	int mid = (l + r) / 2;
	if(tr <= mid) {
		return query(id * 2,l,mid,tl,tr);
	}
	else if(tl > mid) {
		return query(id * 2 + 1,mid + 1,r,tl,tr);
	}
	else {
		return query(id * 2,l,mid,tl,tr) + query(id * 2 + 1,mid + 1,r,tl,tr);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		int x;
		cin>>x;
		update(1,1,n,i,i,x);
	}
	while(m --) {
		int op;cin>>op;
		if(op == 1) {
			int x,y,k;
			cin>>x>>y>>k;
			update(1,1,n,x,y,k);
		}
		else {
			int x,y;
			cin>>x>>y;
			cout << query(1,1,n,x,y) << "\n";
		}
	}
	cout << endl;
	return 0;
}
