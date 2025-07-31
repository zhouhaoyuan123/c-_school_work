#include <iostream>
#include <algorithm>
using namespace std;
int num[25];
long long ten[25];
bool vis[25];
void get_num(long long x,int num[],int & cnt) {
	cnt = 0;
	while(x) {
		num[cnt ++] = x % 10;
		x /= 10;
	}
	sort(num,num+cnt);
}
long long calc(int cnt) {
	long long ans = 0;
	for(int i = 0;i<cnt;i++) {
		if(!vis[i]) ans = ans * 10 + num[i];
	}
	return ans;
}

int main() {
	long long a,b;
	cin>>a>>b;
	int cnt = 0;
	get_num(a,num,cnt);
	ten[0] = 1;
	for(int i = 1;i<=18;i++) {
		ten[i] = ten[i - 1] * 10;
	}
	long long ans = 0;
	for(int i = 0;i<cnt;i++) {
		int choice = -1;
		for(int j = 0;j<cnt;j++) {
			if(vis[j] || (i == 0 && num[j] == 0)) continue;
			vis[j] = 1;
			long long cur = (ans * 10 + num[j]) * ten[cnt - i - 1] + calc(cnt);
			vis[j] = 0;
			if(cur > b) break;
			choice = j;
		}
		vis[choice] = 1;
		ans = ans * 10 + num[choice];
	}
	cout << ans << endl;
	return 0;
}
