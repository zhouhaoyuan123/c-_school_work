#include <iostream>
#include <iomanip>
using namespace std;
int a[100005],b[100005];
int n,p;
bool judge(double lim) {
	double time_tot = 0;
	for(int i = 1;i<=n;i++) {
		if(1.0 * b[i] - a[i] * lim >= 0) {
			continue;
		}
		time_tot += (a[i]*lim - 1.0*b[i]) / p;
	}
	return time_tot <= lim;
}

int main() {
	cin>>n>>p;
	long long sum = 0;
	for(int i = 1;i<=n;i++) {
		cin>>a[i]>>b[i];
		sum += (1ll * a[i]);
	}
	if(sum <= p) {
		cout << -1;
		return 0;
	}
	double l = 0,r = 1e10;
	while(r - l >= 1e-6) {
		double mid = (l + r) / 2;
		if(judge(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << r;
	return 0;
}
