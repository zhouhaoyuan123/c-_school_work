#include <iostream>
using namespace std;
int a[100005][2];
int b[100005][2];

int main() {
	long long L;
	int n,m;
	cin>>L>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i][0] >> a[i][1];
	}
	for(int i = 1;i<=m;i++) {
		cin>>b[i][0] >> b[i][1];
	}
	long long index = 1,index2 = 1;
	long long ans = 0;
	for(int i = 1,j = 1;i<=n;i++) {
		bool flag = 0;
		while(j<=m && index2 < index + a[i][1]) {
			flag = 1;
			index2 += b[j][1];
			if(b[j][0] == a[i][0]) {
				ans += (b[j][1] - max(1ll * 0,index - (index2 - b[j][1])) - max(1ll * 0,index2 - 1 - (index + a[i][1] - 1)));
			}
			j++;
		}
		if(flag && index2 >= index + a[i][1]) {
			j --;
			index2 -= b[j][1];
		}
		if(!flag) {
			if(b[j][0] == a[i][0]) {
				ans += (b[j][1] - max(1ll * 0,index - (index2 - b[j][1])) - max(1ll * 0,index2 - (index + a[i][1] - 1)));
			}
		}
		index += a[i][1];
	}
	cout << ans << endl;
	return 0;
}
