#include <iostream>
using namespace std;
bool judge(long long num,int k,int n ,int m) {
	return ((m) / (num + 1) * num + (m) % (num + 1))*n >= k;
}

int main() {
	int t;
	cin>>t;
	while(t --) {
		int n,m,k;
		cin>>n>>m>>k;
		long long l = 1,r = m;
		while(l < r) {
			int mid = (l + r) / 2;
			if(judge(mid,k,n,m)) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		cout << l << endl;
	}
	return 0;
}
