#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//5 4 3
//3 2 1
int a[100005],b[100005];
int ans[100005];
priority_queue<int> q;

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++) {
		cin>>b[i];
	}
	int cnt = 0;
	sort(a + 1,a + 1 + n);
	sort(b + 1,b + 1 + n);
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(q.size() < n) {
				q.push(a[i] + b[j]);
			}
			else if(q.top() > a[i] + b[j]) {
				q.pop();
				q.push(a[i] + b[j]);
			}
			else break;
		}
		
	}
	while(!q.empty()) {
		ans[++cnt] = q.top();
		q.pop();
	}
	for(int i = cnt;i>=cnt - n + 1;i--) {
		cout << ans[i] << " ";
	}
	return 0;
}
