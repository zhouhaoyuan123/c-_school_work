#include <iostream>
using namespace std;
int twist[300005];
int dict[300005];
int p[300005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>p[i];
	}
	int cnt = 0;
	for(int i = 2;i<=n-1;i++) {
		if(p[i - 1] < p[i] && p[i] > p[i + 1]) {
			twist[i] = 1;
			dict[++cnt] = i;
		}
		if(p[i - 1] > p[i] && p[i] < p[i + 1]) {
			twist[i] = 2;
			dict[++cnt] = i;
		}
	}
	dict[cnt + 2] = n;
	dict[cnt + 1] = n;
	dict[0] = 1;
	long long ans = 0;
	for(int i = 1;i<cnt;i++) {
		if(twist[dict[i]] == 1 && twist[dict[i + 1]] == 2) {
			ans += 1ll * (dict[i] - dict[i - 1]) * (dict[i + 2] - dict[i + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}
