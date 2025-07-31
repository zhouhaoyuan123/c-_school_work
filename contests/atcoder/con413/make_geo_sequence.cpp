#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
long long num[200005];
int cnt1,cnt2;
bool cmp(long long x,long long y) {
	return abs(x) < abs(y);
}

int main() {
	int T;
	cin>>T;
	while(T --) {
		int n;
		cin>>n;
		cnt1 = 0,cnt2 = 0;
		bool yes = 1;
		for(int i = 1;i<=n;i++) {
			cin>>num[i];
			if(abs(num[i]) != abs(num[1])) {
				yes = 0;
			}
			if(num[i] > 0) cnt1 ++;
			if(num[i] < 0) cnt2 ++;
		}
		if(yes) {
			if(cnt1 == cnt2 || abs(cnt1 - cnt2) == 1 || cnt2 == 0 || cnt1 == 0) {
				cout << "Yes" << "\n";
			}
			else cout << "No" << "\n";
			continue;
		}
		yes = 1;
		sort(num+1,num+1+n,cmp); // normal
		double tmp = 1.0 * num[2] / num[1];
		for(int i = 2;i<n;i++) {
			if(num[i] * num[i] != num[i - 1] * num[i + 1]) {
				yes = 0;
				cout << "No" << "\n";
				break;
			}
		}
		if(yes) {
			cout << "Yes" << "\n";
		}
	}
	cout << endl;
	return 0;
}
