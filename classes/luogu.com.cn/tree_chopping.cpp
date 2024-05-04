#include <iostream>
using namespace std;
int n;
long long m;
int num[1000005];
bool judge(long long lim) {
	long long cnt = 0;
	for(int i = 1;i<=n;i++) {
		if(num[i] > lim) {
			cnt += (num[i] - lim);
		}
	}
	return cnt >= m;
}

int main() {
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	int l = 0,r = 4e5;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(judge(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
