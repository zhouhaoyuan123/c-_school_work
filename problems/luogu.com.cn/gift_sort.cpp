#include <iostream>
#include <algorithm>
using namespace std;
int num[30005];

int main() {
	int w,n;
	cin>>w>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	long long ans = 0;
	for(int i = 1,j = n;i<=n;i++,j--) {
		if(i == j) {
			ans ++;
			break;
		}
		if(num[i] + num[j] <= w) {
			ans ++;
		}
		else {
			i --;
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
