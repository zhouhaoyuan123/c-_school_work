#include <iostream>
#include <string>
using namespace std;
int m;int r;
int a[15];

int cnt_digit(int n) {
	int ans = 0;
	while(n>0) {
		ans+=n % 10;
		n /= 10;
	}
	return ans;
}
bool flag = true;
void dfs(int left,int u,int sindex) {
	if(u == r+1 && left == 0) {
		flag = false;
		for(int i = 1;i<u;i++) {
			if(i != 1) {
				cout << " ";
			}
			cout << a[i];
		}
		cout << endl;
	}
	for(int i = sindex;i<=left;i++) {
		if(u == 1 || cnt_digit(i) == cnt_digit(a[u - 1])) {
			a[u] = i;
			dfs(left-i,u+1,i+1);
		}
	}
}

int main() {
	cin>>r>>m;
	dfs(m,1,0);
	if(flag) {
		cout << -1;
	}
	return 0;
}
