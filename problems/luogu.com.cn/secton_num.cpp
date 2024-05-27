#include <iostream>
using namespace std;
long long num[100005];
long long sum = 0;
bool judge(int n,int m,long long lim) {
	int ans = 0;
	long long buf = 0;
	for(int i = 1;i<=n;i++) {
		buf += num[i];
		if(buf > lim) {
			ans ++;
			buf = num[i];
		}
	}
	if(buf > lim) {
		return false;
	}
	else {
		ans++;
	}
	return ans <= m;
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		sum+=num[i];
	}
	long long l = 0,r = sum;
	//long long ans = 0;
	while(l+1<r) {
		long long mid = (l+r+1) / 2;
		if(judge(n,m,mid)) {
			//ans = mid;
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << r;
	return 0;
}
