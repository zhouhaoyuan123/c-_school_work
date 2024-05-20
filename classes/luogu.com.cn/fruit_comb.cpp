#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int num[10005];
priority_queue <long long,vector<long long>,greater<long long> > q;

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		q.push(num[i]);
	}
	//sort(num+1,num+1+n);
	long long ans = 0;
	while(q.size() > 1) {
		long long cur1 = q.top();
		q.pop();
		long long cur2 = q.top();
		q.pop();
		ans += (cur1 + cur2);
		q.push(cur1 + cur2);
	}
	cout << ans;
	return 0;
}
