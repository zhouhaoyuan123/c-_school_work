#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin>>n;
	int maxn = 1e9,minn = 0;
	for(int i = 1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		maxn = min(maxn,x/y);
		minn = max(minn,x / (y + 1) + 1);
	}
	cout << minn << " " << maxn << endl;
	return 0;
}
