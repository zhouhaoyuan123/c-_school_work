#include <iostream>
using namespace std;
int num[105];
int cnt[105];

int main() {	
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		if(num[i] <= m) {
			cnt[num[i]] ++;
		}
	}
	int tmp = n;
	for(int k = 0;k<=n;k++) {
		for(int i = 1;i<=m;i++) {
			if(cnt[i] == 0) {
				cout << k << endl;
				return 0;
			}
		}
		if(num[tmp] <= m) {
			cnt[num[tmp]] --;
		}
		tmp --;
	}
	return 0;
}
