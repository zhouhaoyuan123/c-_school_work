#include <iostream>
using namespace std;
int cnt[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		int x;
		cin>>x;
		cnt[x] ++;
	}
	int overn = 0,lessn = 0;
	int sum = 0;
	for(int i = 1;i<n;i++) {
		overn += max(0,cnt[i] - 2);
		if(cnt[i] > 0) lessn += max(0,2 - cnt[i]);
		if(cnt[i] > 0 && 2 - cnt[i] > 0) {
			sum ++;
		}
	}
	if(overn >= lessn) cout << overn << endl;
	else {
		cout << overn + (lessn - overn) / 2 << endl;
	}
	return 0;
}
