#include <iostream>
#include <iomanip>
using namespace std;
int n,k;
bool vis[25];
int num[25];
void dfs(int i,int step) {
	if(step == k) {
		for(int j = 1;j<=k;j++) {
			cout << setw(3) << num[j];
		}
		cout << endl;
		return;
	}
	for(int j = i;j<=n;j++) {
		if(!vis[j]) {
			vis[j] = 1;
			num[step + 1] = j;
			dfs(j,step+1);
			vis[j] = 0;
		}
	}
}

int main() {	
	cin>>n>>k;
	dfs(1,0);
	return 0;
}