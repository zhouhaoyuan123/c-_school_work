#include <iostream>
using namespace std;
int cards[105];

int main() {
	int n;
	cin>>n;
	int ans = 0;
	long long cnt = 0;
	for(int i = 1;i<=n;i++) {
		cin>>cards[i];
		cnt += cards[i];
	}
	cnt /= n;
	for(int i = 1;i<=n;i++) {
		if(cards[i] - cnt != 0) {
			ans ++;
			cards[i+1] = cards[i] - cnt + cards[i + 1];
		}
	}
	if(cards[n + 1] != 0) {
		cout << -1;//something went wrong
		return 0;
	}
	cout << ans;
	return 0;
}
