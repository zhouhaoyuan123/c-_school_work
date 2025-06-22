#include <iostream>
using namespace std;
#define N 200005
int father[N];
int find(int u) {
	if(u == father[u]) return u;
	return father[u] = find(father[u]);
}
void merge(int x,int y) {
	father[find(x)] = find(y);
}
void init(int x) {
	for(int i = 1;i<=x;i++) {
		father[i] = i;
	}
}

int main() {
	int n,m,p;
	cin>>n>>m>>p;
	init(n);
	for(int i = 1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		merge(x,y);
	}
	for(int i = 1;i<=p;i++) {
		int x,y;cin>>x>>y;
		if(find(x) == find(y)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
