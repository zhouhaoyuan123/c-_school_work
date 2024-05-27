#include <iostream>
#include <algorithm>
using namespace std;
int height[20005];

int main() {
	int n,b;
	cin>>n>>b;
	for(int i = 1;i<=n;i++) {
		cin>>height[i];
	}
	sort(height+1,height+1+n,greater<int>());
	long long cur = 0;
	for(int i = 1;i<=n;i++) {
		cur += height[i];
		if(cur >= b) {
			cout << i ;
			return 0;
		}
	}
	cout << n;
	return 0;
}
