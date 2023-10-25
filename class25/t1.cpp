#include <iostream>
using namespace std;
int dp[2005],v[40005],c[40005];

int main() {
	int N,V;
	cin>>N>>V;
	int t = 0;
	for(int i = 1;i<=N;i++) {
		int vi,ci,si;
		cin>>vi>>ci>>si;
		int p = 1;
		//体积，价值，数量
		while(si >= p) {
			t++;
			v[t] = p * vi;
			c[t] = p * ci;
			si -= p;
			p*=2;
		}
		if(si > 0) {
			t++;
			v[t] = si * vi;
			c[t] = si * ci;
		}
	}
	N=t;
	for(int i = 1;i<=N;i++) {
		for(int j = V;j>=v[i];j--) {
			dp[j] = max(dp[j - v[i]] + c[i],dp[j]);
		}
	}
	cout << dp[V];
	return 0;
}
