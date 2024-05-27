#include <iostream>
#include <iomanip>
using namespace std;
int n,k;
int check[20000005];
int num[25];
bool judge(int x) {
	if(x < 2) {
		return false;
	}
	if(x == 2) {
		return true;
	}
	for(int i = 2;i*i<=x;i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}
int ans = 0;
void dfs(int i,int sum,int step) {
	if(step == k) {
		if(check[sum] == 2) {
			ans ++;
		}
		else if (check[sum] == 0) {
			check[sum] = judge(sum) + 1;
			if(check[sum] == 2) {
				ans ++;
			}
		}
		return;
	}
	for(int j = i;j<=n;j++) {
		//vis[j] = 1;
		//num[step + 1] = j;
		dfs(j+1,sum+num[j],step+1);
		//vis[j] = 0;
	}
}

int main() {	
	cin>>n>>k;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}