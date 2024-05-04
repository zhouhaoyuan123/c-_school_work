#include <iostream>
using namespace std;
long long sum[100005];
int num[100005];
long long sum2[100005];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		sum[i] = sum[i - 1] + num[i];
	}
	for(int i = n;i>=1;i--) {
		sum2[i] = sum2[i + 1] + sum[n] - sum[i - 1];
	}
	int q;
	cin>>q;
	while(q--) {
		int op;
		cin>>op;
		if(op == 1) {
			int x,y;
			cin>>x>>y;
			cout <<sum[y] - sum[x - 1]<<endl;
		}
		else {
			int x,y;
			cin>>x>>y;
			cout <<1ll * sum2[x] - sum2[y + 1] - (sum[n] - sum[y]) * (y - x + 1)<<endl;
		}
	}
	return 0;
}
