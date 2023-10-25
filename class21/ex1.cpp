#include <iostream>
#include <algorithm>
using namespace std;
//sample of binary_search
int main() {
	int l,r,n,t;
	cin>>n>>t;
	int a[n];
	l = 0,r = n-1;
	for(int i = 0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	while(l<=r) {
		int mid = (l+r) / 2;
		if(t < a[mid]) {
			r = mid - 1;
		}
		else if(t>a[mid]) {
			l = mid + 1;
		}
		else {
			cout << mid;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
