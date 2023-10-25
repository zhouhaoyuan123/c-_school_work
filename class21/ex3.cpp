#include <iostream>
using namespace std;

int main() {
	int n,ans = 0;
	cin>>n;
	int money[5] = {20,10,5,1,0};
	for(int i = 0;i<4;i++) {
		if(n == 0) {
			break;
		}
		ans+=n/money[i];
		n-=n/money[i] * money[i];
	}
	cout << ans;
	return 0;
}
