#include <iostream>
#include <algorithm>
using namespace std;
int f[101];
int n,m;
struct line {
	int f,l;
	int c;
}e[101];
int get(int x) {
	if(f[x] == x) {
		return x;
	}
	return f[x] = get(f[x]);
}
bool cmp(line x,line y) {
	return x.c < y.c;
}
bool merge(int x,int y) {
	if(get(x) == get(y)) {
		return false;
	}
	if(get(x) != get(y)) {
		f[y] = get(x);
	}
	return true;
}
int main() {
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		cin>>e[i].f>>e[i].l>>e[i].c;
	}
	for(int i = 1;i<=n;i++) {
		f[i] = i;
	}
	int cnt = 0,cost = 0;
	sort(e+1,e+1+m,cmp);
	for(int i = 1;i<=m;i++) {
		if(cnt >= n - 1) {
			break;
		}
		if(merge(e[i].f,e[i].l)) {
			cnt++;
			cost+=e[i].c;
		}
	}
	cout << cost;
	return 0;
}
