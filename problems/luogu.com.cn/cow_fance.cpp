#include <iostream>
using namespace std;
int cows[100005];
double num[100005],num2[100005],num3[100005];
int n,f;
bool judge(double lim) {
	num2[0]= 0;
	for(int i = 1;i<=n;i++) {
		num[i] = 0;
		num[i] = 1.0 * cows[i] - lim;
		num2[i] = 0;
		num2[i] = num2[i - 1] + num[i];
	}
	double ans = -(1<<30),left_num = (1<<30);
	for(int i = f;i<=n;i++) {
		left_num = min(left_num,num2[i - f]);
		ans = max(ans,num2[i] - left_num);
	}
	if(ans >= 0) {
		return true;
	}
	return false;
}

int main() {
	cin>>n>>f;
	for(int i = 1;i<=n;i++) {
		cin>>cows[i];
	}
	double l = -(1<<30),r = (1<<30);
	double ans = 0;
	while(r - l > 1e-5) {
		double mid = (l + r) / 2;
		if(judge(mid)) {
			ans = mid;
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << int(r * 1000);
	return 0;
}
