#include <iostream>
using namespace std;
int num[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	int t;
	cin>>t;
	while(t--) {
		int x;
		cin>>x;
		int ans = -1;
		int l = 1,r = n;
		while(l<=r) {
			int mid = (l + r) / 2;
			if(num[mid] < x) {
				l = mid + 1;
			} 
			else if(num[mid] > x) {
				r = mid - 1;
			}
			else {
				ans = mid;
				break;
			}
		}
		cout << ans<<" ";
	}
	return 0;
}
