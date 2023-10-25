#include <iostream>
using namespace std;
int f[101];

int get(int x) {
	if(f[x] == x) {
		return x;
	}
	return get(f[x]);
}

void merg(int x, int y) {
	x = get(x);
	y = get(y);
	if(x!=y)
		f[y] = x;
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		f[i] = i;
	}
	for(int i=1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		merg(x,y);
	}
	int q;
	cin>>q;
	for(int i = 1;i<=q;i++) {
		int x,y;cin>>x>>y;
		if(get(x) == get(y)) {
			cout << "yes"<<endl;
		}
		else {
			cout << "no"<<endl;
		}
	}
	return 0;
}
