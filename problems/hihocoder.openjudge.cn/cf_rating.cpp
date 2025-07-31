#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int minn = -1e9,maxn = 1e9;
	int cnt = 0;
	for(int i = 1;i<=n;i++) {
		int x,d;
		cin>>x>>d;
		if(d == 1) {
			minn = max(minn,1900 - cnt);
		}
		else {
			maxn = min(maxn,1899 - cnt);
		}
		if(minn > maxn) {
			cout << "Impossible" << endl;
			return 0;
		}
		cnt += x;
	}
	if(maxn < 1e9) {
		cout << maxn + cnt << endl;
	}
	else {
		cout << "Infinity" << endl;
	}
	return 0;
}
