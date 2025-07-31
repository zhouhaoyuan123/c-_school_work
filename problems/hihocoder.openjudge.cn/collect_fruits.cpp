#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int num[1005];
priority_queue<int> q;
int main() {
	int n,k;
	cin>>n>>k;
	int num3 = 0;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		num3 = max(num3,num[i]);
	}
	sort(num+1,num+1+n,greater<int>());
	int ans = 0;
	for(int i = 1;i<=num3;i++) {
		while(!q.empty()) q.pop();
		bool flag = 1;
		int j,cnt;
		for(j = 1,cnt = 0;j<=n && cnt < k / 2;j++) {
			if(num[j] < i) {
				flag = 0;
				break;
			}
			q.push(num[j] - i * min((num[j] / i),k / 2 - cnt));
			cnt += min((num[j] / i),k / 2 - cnt);
		}
		if(flag) {
			//j++;
			for(;j<=n;j++) {
				q.push(num[j]);
			}
			int tmp = 0;
			for(int j = 1;j<=k / 2;j++) {
				int cur = q.top();
				tmp += min(q.top(),i);
				q.pop();
				q.push(cur - min(cur,i));
			}
			ans = max(ans,tmp);
			//cout << i << " " << ans << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
