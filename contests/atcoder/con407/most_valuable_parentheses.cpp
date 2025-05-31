#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t --) {
		int n;
		cin>>n;
		priority_queue<long long> q;
		long long ans = 0;
		for(int i = 1;i<=2 * n;i++) {
			int x;
			cin>>x;
			q.push(x);
			if(i % 2) {
				ans += q.top(); 
				q.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
