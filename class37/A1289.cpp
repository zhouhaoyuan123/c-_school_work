#include <iostream>
#include <cmath>
using namespace std;
int Y[10005];
int C[10005];
int main() {
	int N,S;
	cin>>N>>S;
	for(int i = 1;i<=N;i++) {
		cin>>C[i]>>Y[i];
	}
	long long ans = 0;
	for(int i = 1;i<=N;i++) {
		long long minn = C[i];
		for(int j = 1;j<i;j++) {
			minn = min(minn,1ll * C[j] + (i - j) * S);
		}
		ans += Y[i] * minn;
	}
	cout << ans;
	return 0;
}
