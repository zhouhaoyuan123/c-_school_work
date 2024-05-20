#include <iostream>
using namespace std;
long long rocks[50005];

long long L,N,M;
bool judge(long long ans) {
	long long check = 0,start = 0;
	for(int i = 1;i<=N+1;i++) {
		if(rocks[i] - rocks[start] < ans) {
			check++;
		}else {
			start = i;
		}
	}
	return check > M;
}

int main() {
	cin>>L>>N>>M;
	rocks[0] = 1;
	for(int i = 1;i<=N;i++) {
		cin>>rocks[i];
		rocks[i] ++;
	}
	rocks[N + 1] = 1 + L;
	
	long long l = 1,r= 1 + L;
	long long ans = 0;
	while(l<=r) {
		long long mid = (l+r) / 2;
		bool key = judge(mid);
		if(key) {
			r = mid-1;
		}
		else {
			l = mid+1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}
