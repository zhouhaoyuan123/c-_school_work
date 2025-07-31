#include <iostream>
using namespace std;
int num[2000005];
int a[2000005];
int lowbit(int x) {
	return x & (-x);
}
int query(int x) {
	int ans = 0;
	for(;x;x -= lowbit(x)) {
		ans += num[x];
	}
	return ans;
}
void update(int n,int x,int target) {
	for(;x <= n;x += lowbit(x)) {
		num[x] += target;
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
		update(n,i,a[i]);
	}
	while(m --) {
		int op;
		cin>>op;
		if(op == 1) {
			int x,k;
			cin>>x>>k;
			update(n,x,k);
		}
		else {
			int x,y;
			cin>>x>>y;
			cout << query(y) - query(x - 1)<< "\n";
		}
	}
	cout << endl;
	return 0;
}
