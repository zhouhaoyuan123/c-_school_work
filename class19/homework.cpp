#include <iostream>
#include <set>
using namespace std;
int f[101];
int e[101][101],cnt[101];
int get(int x) {
	if(f[x] == x) {
		return x;
	}
	return f[x] = get(f[x]);
}

void merge(int x,int y) {
	if(get(x) != get(y)) {
		f[y] = x;
	}
}

void merge2(int x,int y) {
	for(int i = 0;i<cnt[x];i++) {
		merge(y,e[x][i]);
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		f[i] = i;
		//e[i] = i;
	}
	for(int i = 1;i<=m;i++) {
		int op;cin>>op;
		if(op == 0) {
			int x,y;cin>>x>>y;
			merge(x,y);
		}
		else {
			int x,y;cin>>x>>y;
			e[y][cnt[y] ++] = x;
			merge2(x,y);
		}
	}
	set<int> s;
	for(int i = 1;i<=n;i++) {
		s.insert(get(i));
	}
	cout << s.size();
	return 0;
}
