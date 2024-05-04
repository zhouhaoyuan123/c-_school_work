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
	sort(num+1,num+1+n);
	long long ans = 0;
	for(int i = 1,j = n;j - i >= 0 ;i ++,j --) {
		ans += num[j] - num[i];
	}
	cout << ans;
	return 0;
}
