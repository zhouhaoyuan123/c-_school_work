#include <iostream>
using namespace std;

int main() {
	int n,l,r;
	cin>>n>>l>>r;
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		if(x <= l && y >= r) {
			ans ++;
		}
	}
	cout << ans << endl;
}
