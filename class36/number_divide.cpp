#include <iostream>
using namespace std;
long long num[100005];
int n,m;

bool cmp(long long sum) {
	long long tmp = 0,cnt = 0;
	for(int i = 1;i<=n;i++) {
		if(tmp + num[i] > sum) {
			if(tmp == 0) {
				return 0;
			}
			tmp = 0;
			cnt++;
		}
		tmp += num[i];
	}
	if(tmp != 0) {
		if(tmp > sum) return 0;
		cnt ++;
	}
	return cnt <= m;
}
int main() {
	cin>>n>>m;
	long long sum = 0,maxn = 0;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		maxn = max(maxn,num[i]);
		sum += num[i];
	}
	long long l = maxn;
	long long r = sum;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(l + 1 == r) {
			if(cmp(l) == 0) {
				cout <<r;
				return 0;
			}
			else {
				cout << l;
				return 0;
			}
		}
		if(cmp(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	return 0;
}
