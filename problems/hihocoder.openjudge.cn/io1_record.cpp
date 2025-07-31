#include <iostream>
using namespace std;
int num[100005];
bool vis[100005];
int cnt[100005];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	vis[1] = 1;
	int minn = 0,maxn = 0;
	int num1 = 0;
	for(int i = 1;i<=n;i++) {
		if(maxn < num[i]) {
			cnt[i] --;
		}
		else if(minn < num[i] && maxn > num[i]) {
			cnt[num1] ++;
		}
		maxn = max(maxn,num[i]);
		if(maxn == num[i]) num1 = i;
		if(maxn > num[i]) {
			minn = max(minn,num[i]);
		}
	}
	int ans = num[1];int index = cnt[1];
	for(int i = 2;i<=n;i++) {
		if(index < cnt[i]) {
			ans = num[i];
			index = cnt[i];
		}
		else if(index == cnt[i] && ans > num[i]) {
			ans = num[i];
		}
	}
	cout << ans << endl;
	return 0;
}
