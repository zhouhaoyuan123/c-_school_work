#include <iostream>
using namespace std;
int num[10005];

int main() {
	int n;
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>num[i];
	}
	int ans = 0;
	int cnt = n - 1;
	for(int i = 0;i<n;i++) {
		bool flag = 0;
		if(cnt <= 0) {
			break;
		}
		for(int j = 1;j<=cnt;j++) {
			if(num[j - 1] > num[j]) {
				flag = 1;
				int tmp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = tmp;
				ans ++;
			}
		}
		if(!flag) {
			break;
		}
		cnt --;
	}
	cout << ans;
	return 0;
}
