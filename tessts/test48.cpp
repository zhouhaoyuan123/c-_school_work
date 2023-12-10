#include <cstdio>
#include <iostream>
using namespace std;
int match[10] = {6,2,5,5,4,5,6,3,7,6};
int cnt = 0;int N;

int cnt_match(long long n) {
	int ans = 0;
	if(n == 0) {
		return match[n]; 
	}
	while(n > 0) {
		ans+=match[n % 10];
		n /= 10;
	}
	return ans;
}
long long a[5];
void dfs(int u,int left) {
	if(u == 2) {
		if(left - cnt_match(a[0]+a[1]) == 0 ) {
			cnt++;
			cout << a[0] << " + "<<a[1] << " = "<<a[0] + a[1] << endl;
		}
		return;
	}
	for(int i = 0;i<=9;i++) {
		if(left - match[i] < 2) {
			continue;
		}
		a[u] = a[u] * 10 + i;
		if(a[u] == 0) {
			dfs(u+1,left - match[i]);
		}
		else {
			dfs(u,left - match[i]);
			dfs(u + 1,left - match[i]);
		}
		a[u] -= i;a[u] /= 10; 
	} 
}

int main() {
	//freopen("equ.in","r",stdin);
	//freopen("equ.out","w",stdout);
	cin>>N;
	dfs(0,N - 4);
	cout << cnt;
	return 0;
}
