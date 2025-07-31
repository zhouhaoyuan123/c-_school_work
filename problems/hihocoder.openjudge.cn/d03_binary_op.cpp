#include <iostream>
using namespace std;
int num[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>num[i];
	long long mask = 1;
	long long ans = 0;
	for(int i = 0;i<=30;i++) {
		long long tmp = 0;
		for(int j = 1;j<=n;j++) {
			if((num[j] >= mask && num[j] < mask * 2) && (num[j] & (1 << i))) {
				tmp ++;
			}
		}
		ans += tmp * (tmp - 1) / 2;
		mask *= 2;
	}
	cout << ans << endl;
	return 0;
}
