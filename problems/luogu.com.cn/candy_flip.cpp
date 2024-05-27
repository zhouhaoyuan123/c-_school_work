#include <iostream>
using namespace std;
long long cards[1000005];

int main() {
	int n;
	cin>>n;
	long long ans = 0;
	long long cnt = 0;
	for(int i = 1;i<=n;i++) {
		cin>>cards[i];
		cnt += cards[i];
	}
	cnt /= n;
	cards[1] += (cards[n] - cnt);
	//cards[n] = cnt;
	ans += abs(cards[n] - cnt);
	for(int i = 1;i<n;i++) {
		if(cards[i] - cnt != 0) {
			ans += abs(cards[i] - cnt);
			int tmp = i + 1;
			if(tmp > n) {
				tmp = 1;
			}
			cards[tmp] = cards[i] - cnt + cards[tmp];
			//cards[i] = cnt;
		}
	}
	cout << ans;
	return 0;
}
