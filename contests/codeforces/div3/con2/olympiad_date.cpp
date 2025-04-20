#include <iostream>
#include <cstring>
using namespace std;
int req[10] = {3,1,2,1,0,1,0,0,0,0};
int num[10];

int main() {
	int T;
	cin>>T;
	while(T --) {
		int n;
		cin>>n;
		int cnt = 5;
		memset(num,0,sizeof(num));
		int i;
		num[4] = 999;
		num[6] = 999;
		num[7] = 999;
		num[8] = 999;
		num[9] = 999;
		int ans = 0;
		for(i = 1;i<=n;i++) {
			int x;
			cin>>x;
			if(cnt <= 0) {
				if(ans == 0) {
					ans = i - 1;
				}
				continue;
			}
			if(num[x] >= req[x]) {
				continue;
			}
			num[x] ++;
			if(num[x] == req[x]) {
				cnt --;
			}
		}
		if(cnt <= 0) {
			if(ans == 0) {
				ans = i - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
