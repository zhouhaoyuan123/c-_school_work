#include <iostream>
using namespace std;
int cnt[100005];

int main() {
	int n;
	cin>>n;
	int maxn = 0;
	for(int i = 1;i<=n;i++) {
		int x;
		cin>>x;
		maxn = max(maxn,x);
		cnt[x] ++;
	}
	for(int i = 1;i<=maxn;i++) {
		if(maxn % i == 0) {
			cnt[i] --;
		}
	}
	int maxn2 = 0;
	for(int i = 1;i<=100000;i++) {
		if(cnt[i]) {
			maxn2 = max(i,maxn2);
		}
	}
	cout << maxn << " " << maxn2 << endl;
	return 0;
}
