#include <iostream>
using namespace std;
int n,m;
int vis[200005];
int fa[200005];
int get(int x) {
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x,int y) {
	fa[get(x)] = get(y);
}

int main() {
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		fa[i] = i;
	}
	if(n != m) {
		cout << "No" << endl;
		return 0;
	}
	while(m --) {
		int a,b;
		cin>>a>>b;
		vis[a] ++;
		vis[b] ++;
		merge(a,b);
	}
	for(int i = 1;i<=n;i++) {
		if(vis[i] != 2) {
			cout << "No" << endl;
			return 0;
		}
	}
	for(int i = 2;i<=n;i++) {
		if(get(fa[i]) != get(fa[i - 1])) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}
