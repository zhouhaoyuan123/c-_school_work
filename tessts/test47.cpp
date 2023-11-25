#include <iostream>
#include <cstdio>
using namespace std;
int n;int a[25];
void dfs(int u,int dep,int cnt) {
	if(dep == n) {
		if(cnt != n) {
			return;
		}
		cout << n <<"=";
		bool flag = false;
		for(int i = 0;i<n;i++) {
			if(flag) {
				cout << "+";
			}
			else {
				flag = true;
			}
			cout << a[i];
		}
		cout << endl;
		return;
	}
	if(u > n) {
		return;
	}
	a[dep] = u;
	dfs(u,dep+1,cnt + u);
	dfs(u+1,dep + 1,cnt+u);
	dfs(u+1,dep,cnt);
}

int main() {
	//freopen("split.in","r",stdin);
	//freopen("split.out","w",stdout);
	cin>>n;
	dfs(1,0,0);
	return 0;
}

