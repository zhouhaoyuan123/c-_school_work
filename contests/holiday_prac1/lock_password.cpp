#include <iostream>
using namespace std;
int npassword[5],opassword[5];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=3;i++) {
		cin>>npassword[i];
	}
	for(int j = 1;j<=3;j++) {
		cin>>opassword[j];
	}
	int a[5];
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		a[1] = i;
		for(int j = 1;j<=n;j++) {
			a[2] = j;
			for(int k = 1;k<=n;k++) {
				a[3] = k;
				bool flag = true,flag2 = true,decison = false;
				for(int l = 1;l<=3;l++) {
					bool tmp = false,tmp2 = false;
					for(int m = -2;m<=2;m++) {
						if((npassword[l] - m - 1 + n) % n + 1 == a[l]) {
							tmp = true;
						}
						if((opassword[l] - 1 - m + n) % n + 1 == a[l]) {
							tmp2 = true;
						}
					}
					flag &= tmp;
					flag2 &= tmp2;
				}
				decison |= flag,decison |= flag2;
				ans += int(decison);
			}
		}
	}
	cout << ans;
	return 0;
}
