#include <iostream>
using namespace std;
int f[5005][5005];
const int maxn = 5005;

void plus_num(int a[],int b[],int ans[]) {
	for(int i = 0;i<maxn;i++) {
		ans[i] = ans[i] + a[i] + b[i];
		if(ans[i] > 9) {
			ans[i+1] ++;
			ans[i] -= 10;
		}
	}	
}

int main() {
	int n;
	cin>>n;
	f[0][0] = 1;
	f[1][0] = 1;
	for(int i = 2;i<=n;i++) {
		plus_num(f[i - 1],f[i - 2],f[i]);
	}
	int tmp = maxn - 1;
	for(int i = maxn - 1;i>0 && f[n][tmp] == 0;i--) {
		tmp--;
	}
	for(int i = tmp;i>=0;i--) {
		cout << f[n][i];
	}
	return 0;
}
