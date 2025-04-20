#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int num[200005];

int main() {
	int t;
	cin>>t;
	while(t --) {
		int n,x;
		cin>>n>>x;
		memset(num,0,sizeof(num));
		for(int i = 1;i<=n;i++) {
			cin>>num[i];
		}
		sort(num+1,num+1+n,greater<int>());
		int ans = 0;
		for(int i = 1;i<=n;i++) {
			int cnt = 1;
			while(i <= n && cnt * num[i] < x) {
				cnt ++;
				i ++;
			}
			if(i <= n) {
				ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
