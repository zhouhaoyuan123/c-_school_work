#include <iostream>
#include <algorithm>
using namespace std;
int num[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	int t;
	cin>>t;
	while(t--) {
		int x;
		cin>>x;
		int ans = -1;
		int l = 1,r = n;
		while(l<=r) {
			int mid = (l + r) / 2;
			if(mid == l) {
				break;
			}
			if(num[mid] < x) {
				l = mid;
			} 
			else if(num[mid] > x) {
				r = mid;
			}
			else {
				ans = num[mid];
				l = mid,r = mid;
				break;
			}
		}
		if(num[r] <= x) {
			ans = num[r];
		}
		else if(num[l] <= x) {
			ans = num[l];
		}
		cout << ans<<endl;
	}
	return 0;
}
