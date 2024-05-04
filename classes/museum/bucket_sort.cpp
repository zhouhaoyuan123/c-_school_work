#include <iostream>
using namespace std;
int a[8] = {0,1,7,3,5,7,7,6};
int cnt[8];
int sum[8];
int ans[8];

int main() {
	for(int i = 1;i<=7;i++) {
		cnt[a[i]] ++;
	}
//	for(int i = 0;i<=7;i++) {
//		if(cnt[i] != 0) {
//			for(int j = 0;j<cnt[i];j++) {
//				cout << i <<" ";
//			}
//		}
//	}
	sum[0] = cnt[0];
	for(int i = 1;i<=7;i++) {
		sum[i] = sum[i - 1] + cnt[i];
	}
	for(int i = 7;i>=1;i--) {
		ans[i] = sum[a[i]] --;
	}
	for(int i=1;i<=7;i++) {
		cout << ans[i]<<" ";
	}
	return 0;
}
