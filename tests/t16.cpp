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
	for(int i = 1;i<=n;i++) {
		if(cnt[i] == 1) lessn ++;
		else if(cnt[i] >= 3) overn += cnt[i] - 2;
	}
	if(overn >= lessn) cout << overn << endl;
	else {
		cout << (overn+lessn) / 2 << endl;
	}
	return 0;
}
