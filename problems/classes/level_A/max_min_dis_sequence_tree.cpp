#include <iostream>
using namespace std;
struct node {
	int x,y;
	int maxn,minn;
}tree[4000005];
int num[1000005];
int n,m;
void build(int id,int l,int r) {
	if(l > r) return;
	if(l == r) {
		tree[id].x = l;
		tree[id].y = r;
		tree[id].maxn = num[l];
		tree[id].minn = num[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2,l,mid);
	build(id * 2 + 1,mid + 1,r);
	tree[id].x = l;
	tree[id].y = r;
	tree[id].maxn = max(tree[id * 2].maxn,tree[id * 2 + 1].maxn);
	tree[id].minn = min(tree[id * 2].minn,tree[id * 2 + 1].minn);
}
int query(int id,int l,int r) {
	if(l > r) return 0;
	if(tree[id].x == tree[id].y) {
		return tree[id].maxn;
	}
	int mid = (tree[id].x + tree[id].y) / 2;
	if(r <= mid) {
		return query(id * 2,l,r);
	}
	else if(l > mid) {
		return query(id * 2 + 1,l,r);
	}
	else {
		return max(query(id * 2,l,mid),query(id * 2 + 1,mid + 1,r));
	}
}
int query2(int id,int l,int r) {
	if(l > r) return 0x3f3f3f3f;
	if(tree[id].x == tree[id].y) {
		return tree[id].minn;
	}
	int mid = (tree[id].x + tree[id].y) / 2;
	if(r <= mid) {
		return query2(id * 2,l,r);
	}
	else if(l > mid) {
		return query2(id * 2 + 1,l,r);
	}
	else {
		return min(query2(id * 2,l,mid),query2(id * 2 + 1,mid + 1,r));
	}
}

int main() {
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	build(1,1,n);
	while(m --) {
		int x,y;
		cin>>x>>y;
		cout << query(1,x,y) - query2(1,x,y) << endl;
	}
	return 0;
}
