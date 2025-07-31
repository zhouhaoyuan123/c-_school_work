#include <iostream>
#include <algorithm>
using namespace std;
long long num[100005];
long long dis[100005];

int main() {
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	for(int i = 1;i<=n;i++) {
		dis[i] = num[i] - i;
	}
	while(q --) {
		long long x;
		cin>>x;
		int id = lower_bound(dis+1,dis+1+n,x) - dis;
		if(id == 0) {
			cout << num[n] + x - dis[n] << "\n";
		}
		else {
			cout << num[id - 1] + (x - dis[id - 1]) << "\n";
		}
	}
	cout << endl;
	return 0;
}
