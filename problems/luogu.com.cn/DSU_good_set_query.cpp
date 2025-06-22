#include <iostream>
using namespace std;
#define N 200005
long long father[N];
long long val[N];
int find(int u) {
	if(u == father[u]) return u;
	int root = find(father[u]);
	val[u] = val[father[u]] + val[u];
	father[u] = root;
	return root;
}
int merge(int x,int y,int v) {
	int fx = find(x);
	int fy = find(y);
	if(fx == fy) {
		if(val[x] == val[y] + v) return 1;
		else return 0;
	}
	father[fx] = fy;
	val[fx] = v - val[x] + val[y];
	return 1;
}
void init(int x) {
	for(int i = 1;i<=x;i++) {
		father[i] = i;
	}
}

int main() {
	int n,q;
	cin>>n>>q;
	init(q);
	for(int i = 1;i<=q;i++) {
		int a,b,d;
		cin>>a>>b>>d;
		if(merge(a,b,d)) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
