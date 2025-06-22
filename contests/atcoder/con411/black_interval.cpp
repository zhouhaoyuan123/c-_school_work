#include <iostream>
using namespace std;
int a[500005];

int main() {
	int n,q;
	cin>>n>>q;
	int ans = 0;
	while(q --) {
		int x;
		cin>>x;
		if(x == 1) {
			if(a[x] && !a[x + 1]) {
				ans --;
			}
			else if(!a[x] && !a[x + 1]) {
				ans ++;
			}
		}
		else if(x == n) {
			if(a[x] && !a[x - 1]) {
				ans --;
			}
			else if(!a[x] && !a[x - 1]) {
				ans ++;
			}
		}
		else {
			if(a[x] && a[x - 1] && a[x + 1]) {
				ans ++;
			}
			else if(a[x] && !a[x - 1] && !a[x + 1]) {
				ans --;
			}
			else if(!a[x] && a[x - 1] && a[x + 1]) {
				ans --;
			}
			else if(!a[x] && !a[x - 1] && !a[x + 1]) {
				ans ++;
			}
		}
		a[x] = !a[x];
		if(n == 1) {
			cout << a[x] << "\n";
			continue;
		}
		cout << ans << "\n";
	}
	cout << endl;
	return 0;
}
