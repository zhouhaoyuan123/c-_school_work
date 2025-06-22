#include <iostream>
using namespace std;
int diff[1000005];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++) {
		int l,r;
		cin>>l>>r;
		diff[l] ++;
		diff[r + 1] --;
	} 
	int cur = 0;
	int ans = m;
	for(int i = 1;i<=n;i++) {
		cur += diff[i];
		ans = min(ans,cur);
	}
	cout << ans << endl;
	return 0;
}
