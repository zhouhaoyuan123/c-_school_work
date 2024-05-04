#include <iostream>
#include <algorithm>
using namespace std;
long long num[5000005];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	for(int i = 0;i<n;i++) {
		cin>>num[i];
	}
	sort(num,num+n);
	cout << num[k];
	return 0;
}
