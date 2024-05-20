#include <iostream>
using namespace std;

int main() {
	int ans = 0;
	int cur = 5;
	int cnt = 0;
	int n;
	cin>>n;
	while(ans < n) {
		ans += cur;
		cur = cur * 2 + 5;
		cnt++;
	}
	cout << cnt;
	return 0;
}
